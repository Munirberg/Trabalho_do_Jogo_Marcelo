#include "wasm4.h"
#include <stdint.h>

int pget(int x, int y) {
    if (x < 0 || x > 159 || y < 0 || y > 159) { return 0; }
    int idx   = (y * 160 + x) >> 2;
    int shift = (x & 0b11) << 1;
    int mask  = 0b11 << shift;
    return ((FRAMEBUFFER[idx] & mask) >> shift) + 1;
}

void draw_maze() {
    *DRAW_COLORS = 0x03;
    rect(145, 146, 15, 11);
    rect(146, 157, 14, 3);

    *DRAW_COLORS = 0x04;
    rect(15, 0, 2, 18);
    rect(137, 0, 2, 13);
    rect(147, 0, 2, 33);
    rect(69, 3, 36, 2);
    rect(69, 5, 2, 13);
    rect(103, 5, 2, 7);
    rect(23, 6, 37, 2);
    rect(40, 8, 2, 10);
    rect(58, 8, 2, 16);
    rect(76, 10, 27, 2);
    rect(105, 10, 32, 2);
    rect(76, 12, 2, 12);
    rect(149, 12, 11, 2);
    rect(0, 15, 6, 2);
    rect(17, 16, 23, 2);
    rect(4, 17, 2, 41);
    rect(81, 18, 58, 2);
    rect(81, 20, 2, 7);
    rect(103, 20, 2, 37);
    rect(137, 20, 2, 6);
    rect(60, 22, 16, 2);
    rect(13, 24, 29, 2);
    rect(83, 25, 6, 2);
    rect(13, 26, 2, 21);
    rect(40, 26, 2, 8);
    rect(87, 27, 2, 36);
    rect(112, 30, 26, 2);
    rect(152, 30, 6, 2);
    rect(42, 31, 10, 3);
    rect(149, 31, 3, 2);
    rect(52, 32, 35, 2);
    rect(112, 32, 2, 18);
    rect(137, 32, 2, 32);
    rect(156, 32, 2, 51);
    rect(65, 34, 2, 11);
    rect(42, 36, 14, 2);
    rect(118, 36, 13, 2);
    rect(55, 38, 2, 8);
    rect(118, 38, 2, 12);
    rect(129, 38, 2, 6);
    rect(57, 44, 8, 2);
    rect(15, 45, 31, 2);
    rect(114, 48, 4, 2);
    rect(126, 48, 11, 2);
    rect(126, 50, 2, 7);
    rect(44, 53, 34, 2);
    rect(44, 55, 2, 24);
    rect(76, 55, 2, 10);
    rect(105, 55, 21, 2);
    rect(6, 56, 15, 2);
    rect(26, 56, 9, 2);
    rect(19, 58, 2, 20);
    rect(33, 58, 2, 32);
    rect(54, 59, 16, 2);
    rect(54, 61, 2, 4);
    rect(89, 61, 16, 2);
    rect(56, 63, 20, 2);
    rect(103, 63, 2, 8);
    rect(4, 64, 11, 2);
    rect(4, 66, 2, 28);
    rect(13, 66, 2, 7);
    rect(105, 69, 43, 2);
    rect(139, 71, 2, 8);
    rect(146, 71, 2, 17);
    rect(6, 76, 13, 2);
    rect(46, 77, 93, 2);
    rect(107, 79, 2, 34);
    rect(158, 81, 2, 2);
    rect(115, 86, 31, 2);
    rect(35, 88, 30, 2);
    rect(73, 88, 24, 2);
    rect(155, 88, 2, 58);
    rect(52, 90, 2, 12);
    rect(63, 90, 2, 15);
    rect(73, 90, 2, 23);
    rect(95, 90, 2, 15);
    rect(6, 92, 19, 2);
    rect(109, 93, 10, 2);
    rect(23, 94, 2, 8);
    rect(117, 95, 2, 13);
    rect(136, 96, 19, 2);
    rect(136, 98, 2, 43);
    rect(25, 100, 27, 2);
    rect(11, 103, 52, 2);
    rect(83, 103, 12, 2);
    rect(11, 105, 2, 26);
    rect(119, 106, 11, 2);
    rect(128, 108, 2, 10);
    rect(83, 110, 2, 49);
    rect(17, 111, 56, 2);
    rect(94, 111, 13, 2);
    rect(17, 113, 2, 12);
    rect(107, 115, 6, 3);
    rect(94, 116, 13, 2);
    rect(113, 116, 15, 2);
    rect(92, 117, 2, 33);
    rect(40, 118, 43, 2);
    rect(120, 118, 2, 32);
    rect(40, 120, 2, 14);
    rect(19, 123, 12, 2);
    rect(50, 124, 16, 2);
    rect(29, 125, 2, 24);
    rect(64, 126, 2, 8);
    rect(13, 129, 12, 2);
    rect(23, 131, 2, 8);
    rect(42, 132, 22, 2);
    rect(6, 137, 17, 2);
    rect(122, 137, 14, 4);
    rect(41, 138, 32, 2);
    rect(41, 140, 2, 9);
    rect(143, 144, 12, 2);
    rect(157, 144, 3, 2);
    rect(0, 146, 24, 2);
    rect(143, 146, 2, 3);
    rect(31, 147, 10, 2);
    rect(43, 147, 40, 2);
    rect(129, 147, 14, 2);
    rect(22, 148, 2, 11);
    rect(94, 148, 26, 2);
    rect(24, 157, 59, 2);
    rect(85, 157, 61, 2);
    rect(144, 159, 2, 1);
}

int x, y;
int ganhou;

void start() {
    PALETTE[0] = 0xcccec7; // cor 1 - fundo off-white
    PALETTE[1] = 0xa09f97; // cor 2 - midtone claro
    PALETTE[2] = 0x77746f; // cor 3 - midtone escuro (jogador)
    PALETTE[3] = 0x2e2622; // cor 4 - quase-preto (paredes)

    x = 5;
    y = 5;
    ganhou = 1;
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

    if (ganhou){
        draw_maze();
    }

    if (pget(x,   y  ) == 4 ||
        pget(x+1, y  ) == 4 ||
        pget(x,   y+1) == 4 ||
        pget(x+1, y+1) == 4 ||
        x > 159 || x < 0    ||
        y > 159 || y < 0) {
        x -= dx;
        y -= dy;
    }

    if (pget(x, y) == 3) {
        ganhou = 0;
    }

    if (!ganhou) {
        *DRAW_COLORS = 4;
        text("Ganhou pae", 50, 50);
    }

    *DRAW_COLORS = 0x02;
    rect(x, y, 2, 2);
}