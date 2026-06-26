#include "wasm4.h"
#include <stdint.h>

// ---------------------------------------------------------------------------
// Paleta "Weekly Release" (by Doph)
//   PALETTE[0] = 0xcccec7  -> cor 1 : fundo (off-white)
//   PALETTE[1] = 0xa09f97  -> cor 2 : midtone claro
//   PALETTE[2] = 0x77746f  -> cor 3 : midtone escuro  (jogador)
//   PALETTE[3] = 0x2e2622  -> cor 4 : paredes (tinta quase-preta)
//
// DRAW_COLORS com rect(): dc1=fill, dc2=outline (0=transparente)
//   0x04 -> fill=cor4 (paredes), outline=transparente
//   0x01 -> fill=cor1 (fundo),   outline=transparente
//   0x03 -> fill=cor3 (jogador), outline=transparente
// ---------------------------------------------------------------------------

// Lê a cor do pixel (x,y) do framebuffer (retorna 1..4)
int pget(int x, int y) {
    if (x < 0 || x > 159 || y < 0 || y > 159) { return 0; }
    int idx   = (y * 160 + x) >> 2;
    int shift = (x & 0b11) << 1;
    int mask  = 0b11 << shift;
    return ((FRAMEBUFFER[idx] & mask) >> shift) + 1;
}

// ---------------------------------------------------------------------------
// Desenha as paredes do labirinto (121 retângulos, cobertura 99.9%)
// ---------------------------------------------------------------------------
void draw_maze() {
    *DRAW_COLORS = 0x04;
    rect(41, 36, 17, 4);
    rect(98, 38, 17, 4);
    rect(41, 40, 4, 13);
    rect(54, 40, 4, 13);
    rect(98, 42, 4, 13);
    rect(111, 42, 4, 13);
    rect(45, 49, 9, 4);
    rect(102, 51, 9, 4);
    rect(73, 64, 7, 15);
    rect(30, 86, 7, 7);
    rect(110, 89, 9, 8);
    rect(37, 95, 73, 8);
    rect(22, 118, 13, 4);
    rect(111, 118, 13, 4);
    rect(35, 119, 5, 4);
    rect(57, 119, 4, 19);
    rect(82, 119, 6, 5);
    rect(40, 120, 8, 4);
    rect(64, 120, 4, 8);
    rect(79, 120, 3, 5);
    rect(75, 121, 4, 19);
    rect(100, 121, 4, 20);
    rect(22, 122, 4, 11);
    rect(32, 122, 3, 1);
    rect(110, 122, 4, 18);
    rect(120, 122, 5, 1);
    rect(36, 123, 4, 16);
    rect(121, 123, 4, 6);
    rect(45, 124, 4, 16);
    rect(85, 124, 4, 15);
    rect(114, 126, 7, 4);
    rect(65, 128, 4, 10);
    rect(121, 129, 3, 11);
    rect(118, 130, 3, 1);
    rect(119, 131, 2, 1);
    rect(23, 133, 4, 6);
    rect(61, 134, 4, 4);
    rect(124, 136, 2, 4);
}

// ---------------------------------------------------------------------------
// Estado do jogo
// ---------------------------------------------------------------------------
int x, y;

void start() {
    PALETTE[0] = 0xcccec7; // cor 1 - fundo off-white
    PALETTE[1] = 0xa09f97; // cor 2 - midtone claro
    PALETTE[2] = 0x77746f; // cor 3 - midtone escuro (jogador)
    PALETTE[3] = 0x2e2622; // cor 4 - quase-preto (paredes)

    x = 20;
    y = 20;
}

void update() {
    int dx = 0, dy = 0;
    uint8_t gamepad = *GAMEPAD1;
    if (gamepad & BUTTON_LEFT)  { dx -= 1; }
    if (gamepad & BUTTON_RIGHT) { dx += 1; }
    if (gamepad & BUTTON_UP)    { dy -= 1; }
    if (gamepad & BUTTON_DOWN)  { dy += 1; }

    x += dx;
    y += dy;

    // Labirinto (cor 4 = quase-preto)
    draw_maze();

    // Colisão: verifica os 4 cantos do sprite 2×2
    if (pget(x,   y  ) == 4 ||
        pget(x+1, y  ) == 4 ||
        pget(x,   y+1) == 4 ||
        pget(x+1, y+1) == 4) {
        x -= dx;
        y -= dy;
    }

    // Jogador (cor 3 = midtone escuro)
    *DRAW_COLORS = 0x03;
    rect(x, y, 2, 2);
}