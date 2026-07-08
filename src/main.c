#include "wasm4.h"
#include <stdint.h>
#include "util.h"

const uint8_t chave[23] = { 0x00,0x00,0x00,0x1a,0x80,0x06,0x00,0x01,0xa0,0x00,0x60,0x00,0x18,0x00,0x6a,0xa0,0x60,0x0e,0x18,0x03,0x81,0xaa,0x80 };


void draw_maze2() {
    *DRAW_COLORS = 0x03;
    rect(0, 0, 15, 7);
    rect(0, 7, 14, 7);
    rect(0, 14, 8, 1);
    rect(9, 14, 3, 1);
    rect(145, 145, 15, 8);
    rect(146, 153, 14, 7);

    *DRAW_COLORS = 0x04;
    rect(69, 3, 23, 1);
    rect(107, 3, 37, 1);
    rect(57, 6, 13, 1);
    rect(14, 7, 32, 1);
    rect(146, 7, 9, 1);
    rect(73, 11, 19, 1);
    rect(111, 11, 34, 1);
    rect(14, 13, 16, 1);
    rect(12, 14, 3, 1);
    rect(51, 14, 7, 1);
    rect(50, 18, 6, 1);
    rect(119, 18, 19, 1);
    rect(82, 19, 30, 1);
    rect(17, 22, 13, 1);
    rect(87, 24, 23, 1);
    rect(26, 26, 20, 1);
    rect(92, 28, 7, 1);
    rect(8, 29, 6, 1);
    rect(32, 31, 7, 1);
    rect(119, 32, 12, 1);
    rect(144, 34, 11, 1);
    rect(87, 35, 12, 1);
    rect(38, 36, 13, 1);
    rect(55, 36, 10, 1);
    rect(17, 39, 10, 1);
    rect(137, 39, 15, 1);
    rect(119, 40, 3, 1);
    rect(128, 40, 2, 1);
    rect(82, 42, 19, 1);
    rect(18, 43, 33, 1);
    rect(56, 43, 18, 1);
    rect(5, 47, 9, 1);
    rect(129, 47, 12, 1);
    rect(33, 48, 22, 1);
    rect(151, 49, 9, 1);
    rect(54, 51, 66, 1);
    rect(43, 53, 6, 1);
    rect(9, 54, 10, 1);
    rect(140, 56, 20, 1);
    rect(28, 57, 6, 1);
    rect(64, 58, 35, 1);
    rect(108, 58, 22, 1);
    rect(9, 60, 3, 1);
    rect(136, 61, 18, 1);
    rect(72, 63, 27, 1);
    rect(43, 64, 12, 1);
    rect(5, 65, 11, 1);
    rect(119, 65, 18, 1);
    rect(72, 67, 27, 1);
    rect(143, 67, 11, 1);
    rect(5, 69, 17, 1);
    rect(36, 71, 29, 1);
    rect(125, 73, 19, 1);
    rect(86, 74, 23, 1);
    rect(152, 75, 8, 1);
    rect(45, 77, 28, 1);
    rect(5, 79, 12, 1);
    rect(150, 80, 3, 1);
    rect(95, 81, 25, 1);
    rect(0, 87, 10, 1);
    rect(102, 88, 24, 1);
    rect(21, 89, 8, 1);
    rect(109, 94, 19, 1);
    rect(9, 95, 28, 1);
    rect(45, 95, 14, 1);
    rect(63, 95, 24, 1);
    rect(9, 100, 67, 1);
    rect(0, 102, 10, 1);
    rect(115, 102, 7, 1);
    rect(10, 107, 66, 1);
    rect(127, 109, 13, 1);
    rect(109, 115, 13, 1);
    rect(143, 115, 8, 1);
    rect(16, 116, 71, 1);
    rect(6, 118, 5, 1);
    rect(10, 123, 35, 1);
    rect(49, 123, 47, 1);
    rect(102, 126, 26, 1);
    rect(58, 130, 24, 1);
    rect(87, 132, 16, 1);
    rect(143, 132, 17, 1);
    rect(10, 134, 25, 1);
    rect(7, 135, 4, 1);
    rect(65, 138, 17, 1);
    rect(107, 138, 39, 1);
    rect(6, 140, 29, 1);
    rect(86, 143, 2, 2);
    rect(92, 143, 16, 1);
    rect(6, 144, 4, 1);
    rect(58, 144, 28, 1);
    rect(144, 144, 16, 1);
    rect(58, 148, 12, 1);
    rect(74, 148, 64, 1);
    rect(9, 151, 41, 1);
    rect(98, 153, 48, 1);
    rect(48, 156, 11, 1);
}
void draw_maze1() {
    *DRAW_COLORS = 3;
    rect(145, 146, 15, 11);
    rect(146, 157, 14, 3);

    *DRAW_COLORS = 4;
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

int x, y, ganhou, temChave, nivel;

void start() {
    PALETTE[0] = 0xcccec7;
    PALETTE[1] = 0xa09f97;
    PALETTE[2] = 0x77746f;
    PALETTE[3] = 0x2e2622;

    x = 5;
    y = 5;
    ganhou = 0;
    temChave = 0;
    nivel = 1;
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

    Shape player = {x, y, 2, 2};
    Shape chave1 = {124, 122, 9, 10};
    if(nivel == 1){
       if (!ganhou){
           draw_maze1();
   
           if (!temChave){
               *DRAW_COLORS = 0x4320;
               blit(chave, 124, 122, 9, 10, BLIT_2BPP);
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
   
           if (pget(x, y) == 3 && temChave) {
               nivel = 2;
           }
   
           *DRAW_COLORS = 0x02;
           rect(x, y, 2, 2);
       }
    }

   else if(nivel == 2){
      draw_maze2();
   }




    if (hit_box_box(player, chave1)) {temChave = 1;}

    if (ganhou) {
        *DRAW_COLORS = 4;
        text("YOU WON!", 46, 60);
    }


}
