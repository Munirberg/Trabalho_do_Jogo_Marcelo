#!/usr/bin/env python3
"""
maze_to_c.py — Converte uma imagem de labirinto em uma função draw_maze() para WASM-4.

Uso:
    python3 maze_to_c.py <imagem> [opções]

Exemplos:
    python3 maze_to_c.py labirinto.png
    python3 maze_to_c.py labirinto.jpeg --output draw_maze.c
    python3 maze_to_c.py labirinto.png --function-name draw_walls --stats

Requisitos:
    pip install Pillow numpy
"""

import argparse
import sys
import numpy as np
from PIL import Image


# ---------------------------------------------------------------------------
# Paleta "Weekly Release" em RGB
# ---------------------------------------------------------------------------
PALETTE_RGB = {
    1: np.array([204, 206, 199]),  # fundo off-white
    2: np.array([160, 159, 151]),  # midtone claro
    3: np.array([119, 116, 111]),  # midtone escuro
    4: np.array([46,  38,  34]),   # quase-preto (paredes principais)
}

# Cores consideradas "parede" (não-corredor), mapeadas para o nibble DRAW_COLORS
WALL_COLORS = {3, 4}

# DRAW_COLORS nibble para cada cor de parede:
#   rect() usa dc1 como fill e dc2 como outline.
#   0xY0 onde Y é o índice da paleta (1..4); dc2=0 = outline transparente.
DRAW_COLOR_FOR = {
    3: 0x03,  # fill = cor 3
    4: 0x04,  # fill = cor 4
}


def load_color_map(path: str) -> np.ndarray:
    """
    Abre a imagem e classifica cada pixel pela cor mais próxima da paleta
    (distância euclidiana no espaço RGB).

    Retorna um array (160, 160) com valores 1..4.
    A imagem é redimensionada para 160x160 se necessário.
    """
    img = Image.open(path).convert("RGB")

    if img.size != (160, 160):
        print(f"[aviso] imagem {img.size} redimensionada para 160x160", file=sys.stderr)
        img = img.resize((160, 160), Image.LANCZOS)

    rgb = np.array(img, dtype=np.float32)  # (160, 160, 3)

    # Calcular distância para cada cor da paleta de uma só vez (vetorizado)
    # palette_stack: (4, 3) → broadcast com rgb (160, 160, 3)
    palette_stack = np.array([PALETTE_RGB[c] for c in sorted(PALETTE_RGB)], dtype=np.float32)
    # distances: (160, 160, 4)
    diff = rgb[:, :, np.newaxis, :] - palette_stack[np.newaxis, np.newaxis, :, :]
    distances = np.linalg.norm(diff, axis=3)

    # argmin retorna 0..3; somamos 1 para ter 1..4
    color_map = distances.argmin(axis=2).astype(np.uint8) + 1
    return color_map


def find_rects(mask: np.ndarray, min_size: int) -> list[tuple[int, int, int, int]]:
    """
    Decomposição greedy de pixels marcados (mask==True) em retângulos (x, y, w, h).

    Algoritmo: para cada linha de cima para baixo, varre da esquerda para
    a direita. Ao encontrar um pixel ainda não visitado, expande
    horizontalmente até o fim do segmento, depois expande verticalmente
    enquanto todas as linhas abaixo tiverem o mesmo segmento intacto.

    min_size: descarta retângulos menores que isso em AMBAS as dimensões
    (elimina ruído de compressão JPEG).
    """
    h, w = mask.shape
    visited = np.zeros_like(mask, dtype=bool)
    rects = []

    for y in range(h):
        x = 0
        while x < w:
            if mask[y, x] and not visited[y, x]:
                # Expansão horizontal
                x_end = x
                while x_end < w and mask[y, x_end] and not visited[y, x_end]:
                    x_end += 1
                rect_w = x_end - x

                if rect_w < min_size:
                    x = x_end + 1
                    continue

                # Expansão vertical
                y_end = y + 1
                while y_end < h:
                    seg_wall = mask[y_end, x:x_end]
                    seg_vis  = visited[y_end, x:x_end]
                    if np.all(seg_wall) and not np.any(seg_vis):
                        y_end += 1
                    else:
                        break
                rect_h = y_end - y

                if rect_w >= min_size or rect_h >= min_size:
                    rects.append((x, y, rect_w, rect_h))
                    visited[y:y_end, x:x_end] = True

                x = x_end
            else:
                x += 1

    return rects


def build_draw_calls(color_map: np.ndarray, min_size: int) -> list[tuple[int, tuple]]:
    """
    Para cada cor de parede, encontra os retângulos e retorna uma lista de
    (draw_color_hex, (x, y, w, h)) ordenada por posição (y, x) para
    minimizar mudanças de DRAW_COLORS consecutivas.
    """
    calls = []
    for color in sorted(WALL_COLORS):
        mask = (color_map == color)
        rects = find_rects(mask, min_size)
        dc = DRAW_COLOR_FOR[color]
        for r in rects:
            calls.append((dc, r))

    # Ordenar por DRAW_COLORS primeiro (agrupa chamadas da mesma cor),
    # depois por y, x dentro de cada grupo → minimiza setagens de DRAW_COLORS
    calls.sort(key=lambda c: (c[0], c[1][1], c[1][0]))
    return calls


def coverage_report(color_map: np.ndarray, calls: list) -> dict:
    """Calcula métricas de cobertura."""
    wall_mask = np.isin(color_map, list(WALL_COLORS))
    reconstructed = np.zeros((160, 160), dtype=bool)
    for (_, (x, y, w, h)) in calls:
        reconstructed[y:y+h, x:x+w] = True

    total_wall  = int(wall_mask.sum())
    covered     = int(np.logical_and(wall_mask, reconstructed).sum())
    extra       = int(reconstructed.sum() - covered)

    return {
        "total_wall":   total_wall,
        "covered":      covered,
        "coverage_pct": covered / total_wall * 100 if total_wall else 0,
        "extra_pixels": extra,
        "num_rects":    len(calls),
    }


def generate_c(calls: list, function_name: str) -> str:
    """Gera o código C da função draw_maze() com mudanças mínimas de DRAW_COLORS."""
    lines = []
    lines.append(f"void {function_name}() {{")

    current_dc = None
    for (dc, (x, y, w, h)) in calls:
        if dc != current_dc:
            if current_dc is not None:
                lines.append("")  # linha em branco entre grupos de cores
            lines.append(f"    *DRAW_COLORS = 0x{dc:02X};")
            current_dc = dc
        lines.append(f"    rect({x}, {y}, {w}, {h});")

    lines.append("}")
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(
        description="Converte imagem de labirinto em função draw_maze() para WASM-4."
    )
    parser.add_argument("image", help="Caminho para a imagem do labirinto.")
    parser.add_argument(
        "--min-size", type=int, default=2,
        help="Tamanho mínimo de lado de um retângulo (padrão: 2)."
    )
    parser.add_argument(
        "--function-name", default="draw_maze",
        help="Nome da função C gerada (padrão: draw_maze)."
    )
    parser.add_argument(
        "--output", default=None,
        help="Arquivo de saída. Se omitido, imprime no stdout."
    )
    parser.add_argument(
        "--stats", action="store_true",
        help="Imprime estatísticas de cobertura no stderr."
    )

    args = parser.parse_args()

    color_map = load_color_map(args.image)
    calls     = build_draw_calls(color_map, args.min_size)
    code      = generate_c(calls, args.function_name)

    if args.stats or args.output:
        report = coverage_report(color_map, calls)
        # Contar rects por cor
        by_color = {}
        for (dc, _) in calls:
            by_color[dc] = by_color.get(dc, 0) + 1
        detail = ", ".join(f"0x{dc:02X}={n}" for dc, n in sorted(by_color.items()))
        print(
            f"[info] {report['num_rects']} retângulos ({detail}) | "
            f"cobertura {report['coverage_pct']:.1f}% | "
            f"pixels extras {report['extra_pixels']}",
            file=sys.stderr
        )

    if args.output:
        with open(args.output, "w") as f:
            f.write(code + "\n")
        print(f"[info] salvo em {args.output}", file=sys.stderr)
    else:
        print(code)


if __name__ == "__main__":
    main()