#include "wasm4.h"
#include <stdint.h>
#include <sys/types.h>
#include "util.h"

// desenho da chave que vai ser usado nas fases
const uint8_t chave[23] = { 0x00,0x00,0x00,0x1a,0x80,0x06,0x00,0x01,0xa0,0x00,0x60,0x00,0x18,0x00,0x6a,0xa0,0x60,0x0e,0x18,0x03,0x81,0xaa,0x80 };
#define TYPE_SPEED 10

// fase 3 
void draw_maze3() {
    *DRAW_COLORS = 0x04;
    rect(14, 0, 1, 7);
    rect(41, 0, 1, 7);
    rect(54, 0, 1, 7);
    rect(149, 0, 1, 11);
    rect(62, 2, 1, 16);
    rect(28, 3, 5, 1);
    rect(28, 4, 1, 5);
    rect(32, 4, 1, 14);
    rect(63, 5, 39, 1);
    rect(109, 5, 29, 1);
    rect(42, 6, 12, 1);
    rect(101, 6, 1, 14);
    rect(109, 6, 1, 10);
    rect(63, 10, 31, 1);
    rect(117, 10, 32, 1);
    rect(150, 10, 10, 1);
    rect(0, 11, 10, 1);
    rect(33, 11, 13, 1);
    rect(72, 11, 1, 7);
    rect(84, 11, 1, 3);
    rect(93, 11, 1, 15);
    rect(16, 12, 4, 1);
    rect(45, 12, 1, 11);
    rect(16, 13, 1, 5);
    rect(19, 13, 1, 5);
    rect(75, 14, 4, 1);
    rect(78, 15, 1, 3);
    rect(110, 15, 43, 1);
    rect(152, 16, 1, 16);
    rect(6, 17, 10, 1);
    rect(17, 17, 2, 1);
    rect(20, 17, 12, 1);
    rect(46, 17, 16, 1);
    rect(73, 17, 5, 1);
    rect(6, 18, 1, 11);
    rect(26, 18, 1, 21);
    rect(84, 19, 1, 42);
    rect(38, 20, 1, 20);
    rect(27, 22, 7, 1);
    rect(46, 22, 30, 1);
    rect(13, 23, 7, 1);
    rect(13, 24, 1, 14);
    rect(19, 24, 1, 31);
    rect(85, 25, 8, 1);
    rect(94, 25, 42, 1);
    rect(33, 29, 5, 1);
    rect(46, 29, 15, 1);
    rect(67, 29, 6, 1);
    rect(46, 30, 1, 5);
    rect(60, 30, 1, 14);
    rect(67, 30, 1, 8);
    rect(72, 30, 1, 14);
    rect(90, 31, 62, 1);
    rect(73, 32, 7, 1);
    rect(90, 32, 1, 22);
    rect(107, 32, 1, 15);
    rect(112, 32, 1, 13);
    rect(137, 32, 1, 7);
    rect(27, 34, 7, 1);
    rect(47, 34, 10, 1);
    rect(56, 35, 1, 5);
    rect(0, 37, 13, 1);
    rect(39, 38, 10, 1);
    rect(117, 38, 20, 1);
    rect(138, 38, 22, 1);
    rect(146, 39, 1, 56);
    rect(78, 40, 1, 12);
    rect(97, 41, 1, 20);
    rect(24, 43, 36, 1);
    rect(61, 43, 11, 1);
    rect(33, 44, 1, 3);
    rect(117, 44, 21, 1);
    rect(6, 45, 6, 1);
    rect(137, 45, 1, 8);
    rect(6, 46, 1, 13);
    rect(11, 46, 1, 15);
    rect(153, 47, 1, 95);
    rect(20, 51, 58, 1);
    rect(61, 52, 1, 53);
    rect(72, 52, 1, 58);
    rect(107, 52, 30, 1);
    rect(124, 53, 1, 64);
    rect(27, 56, 30, 1);
    rect(27, 57, 1, 3);
    rect(56, 57, 1, 3);
    rect(130, 57, 8, 1);
    rect(130, 58, 1, 66);
    rect(137, 58, 1, 27);
    rect(28, 59, 28, 1);
    rect(12, 60, 7, 1);
    rect(85, 60, 12, 1);
    rect(98, 60, 20, 1);
    rect(18, 61, 1, 11);
    rect(117, 61, 1, 19);
    rect(7, 64, 8, 1);
    rect(7, 65, 1, 35);
    rect(14, 65, 1, 7);
    rect(25, 65, 36, 1);
    rect(141, 65, 5, 1);
    rect(25, 66, 1, 12);
    rect(36, 66, 1, 20);
    rect(73, 66, 32, 2);
    rect(111, 66, 1, 8);
    rect(141, 66, 1, 19);
    rect(15, 71, 3, 1);
    rect(30, 72, 1, 6);
    rect(53, 73, 1, 13);
    rect(84, 73, 27, 1);
    rect(84, 74, 1, 42);
    rect(12, 77, 13, 1);
    rect(26, 77, 4, 1);
    rect(91, 79, 26, 1);
    rect(91, 80, 1, 36);
    rect(66, 81, 1, 25);
    rect(73, 81, 6, 1);
    rect(78, 82, 1, 71);
    rect(138, 84, 3, 1);
    rect(12, 85, 24, 1);
    rect(37, 85, 16, 1);
    rect(114, 87, 6, 1);
    rect(114, 88, 1, 29);
    rect(119, 88, 1, 22);
    rect(99, 89, 8, 1);
    rect(99, 90, 1, 58);
    rect(106, 90, 1, 35);
    rect(12, 91, 43, 1);
    rect(137, 91, 1, 33);
    rect(54, 92, 1, 5);
    rect(142, 94, 4, 1);
    rect(15, 96, 39, 1);
    rect(15, 97, 1, 42);
    rect(0, 99, 7, 1);
    rect(145, 99, 8, 2);
    rect(20, 103, 8, 1);
    rect(20, 104, 1, 6);
    rect(27, 104, 1, 6);
    rect(32, 104, 29, 1);
    rect(138, 106, 9, 1);
    rect(146, 107, 1, 3);
    rect(0, 108, 11, 1);
    rect(10, 109, 1, 17);
    rect(21, 109, 6, 1);
    rect(138, 109, 8, 1);
    rect(32, 110, 30, 1);
    rect(61, 111, 1, 32);
    rect(66, 112, 1, 12);
    rect(138, 113, 8, 1);
    rect(145, 114, 1, 10);
    rect(16, 115, 31, 1);
    rect(37, 116, 1, 36);
    rect(115, 116, 9, 1);
    rect(119, 117, 1, 8);
    rect(67, 122, 1, 2);
    rect(84, 122, 8, 1);
    rect(22, 123, 11, 1);
    rect(62, 123, 4, 1);
    rect(68, 123, 4, 1);
    rect(84, 123, 1, 7);
    rect(91, 123, 1, 34);
    rect(131, 123, 6, 1);
    rect(146, 123, 3, 1);
    rect(32, 124, 1, 15);
    rect(46, 124, 1, 28);
    rect(54, 124, 1, 33);
    rect(71, 124, 1, 18);
    rect(107, 124, 12, 1);
    rect(0, 125, 10, 1);
    rect(100, 128, 53, 1);
    rect(100, 129, 1, 19);
    rect(16, 130, 12, 1);
    rect(51, 132, 3, 1);
    rect(10, 133, 1, 15);
    rect(106, 134, 42, 1);
    rect(4, 135, 1, 18);
    rect(116, 135, 1, 8);
    rect(128, 135, 1, 19);
    rect(16, 138, 16, 1);
    rect(17, 139, 1, 14);
    rect(134, 141, 19, 1);
    rect(134, 142, 1, 15);
    rect(95, 144, 4, 1);
    rect(26, 146, 1, 14);
    rect(140, 146, 9, 1);
    rect(60, 147, 18, 1);
    rect(101, 147, 21, 1);
    rect(140, 147, 1, 13);
    rect(66, 148, 1, 5);
    rect(101, 148, 1, 9);
    rect(135, 149, 5, 1);
    rect(51, 150, 3, 1);
    rect(38, 151, 8, 1);
    rect(5, 152, 12, 1);
    rect(67, 152, 11, 1);
    rect(92, 152, 3, 1);
    rect(37, 156, 17, 1);
    rect(55, 156, 36, 1);
    rect(102, 156, 32, 1);
}
// fase 2
void draw_maze2() {
    *DRAW_COLORS = 4;
    rect(15, 0, 1, 8);
    rect(143, 0, 1, 4);
    rect(69, 3, 23, 1);
    rect(99, 3, 1, 17);
    rect(107, 3, 36, 1);
    rect(69, 4, 1, 3);
    rect(91, 4, 1, 8);
    rect(51, 5, 1, 10);
    rect(57, 6, 12, 1);
    rect(14, 7, 1, 1);
    rect(16, 7, 30, 1);
    rect(57, 7, 1, 8);
    rect(64, 7, 1, 30);
    rect(146, 7, 9, 1);
    rect(45, 8, 1, 19);
    rect(154, 8, 1, 27);
    rect(73, 11, 18, 1);
    rect(111, 11, 34, 1);
    rect(73, 12, 1, 32);
    rect(111, 12, 1, 8);
    rect(144, 12, 1, 23);
    rect(14, 13, 16, 1);
    rect(8, 14, 1, 16);
    rect(12, 14, 3, 1);
    rect(29, 14, 1, 9);
    rect(52, 14, 5, 1);
    rect(150, 14, 1, 21);
    rect(50, 18, 6, 1);
    rect(119, 18, 19, 1);
    rect(50, 19, 1, 18);
    rect(55, 19, 1, 18);
    rect(82, 19, 17, 1);
    rect(100, 19, 11, 1);
    rect(119, 19, 1, 14);
    rect(137, 19, 1, 21);
    rect(82, 20, 1, 32);
    rect(17, 22, 12, 1);
    rect(17, 23, 1, 17);
    rect(87, 24, 23, 1);
    rect(87, 25, 1, 11);
    rect(109, 25, 1, 27);
    rect(130, 25, 1, 8);
    rect(26, 26, 19, 1);
    rect(26, 27, 1, 13);
    rect(92, 28, 7, 1);
    rect(9, 29, 5, 1);
    rect(92, 29, 1, 4);
    rect(98, 29, 1, 7);
    rect(13, 30, 1, 18);
    rect(32, 31, 7, 1);
    rect(38, 32, 1, 12);
    rect(120, 32, 10, 1);
    rect(145, 34, 5, 1);
    rect(151, 34, 3, 1);
    rect(88, 35, 10, 1);
    rect(39, 36, 11, 1);
    rect(56, 36, 8, 1);
    rect(18, 39, 8, 1);
    rect(138, 39, 14, 1);
    rect(119, 40, 3, 1);
    rect(128, 40, 2, 1);
    rect(151, 40, 1, 10);
    rect(119, 41, 1, 11);
    rect(129, 41, 1, 18);
    rect(83, 42, 18, 1);
    rect(18, 43, 20, 1);
    rect(39, 43, 12, 1);
    rect(56, 43, 17, 1);
    rect(18, 44, 1, 11);
    rect(5, 47, 8, 1);
    rect(130, 47, 11, 1);
    rect(5, 48, 1, 18);
    rect(33, 48, 22, 1);
    rect(140, 48, 1, 9);
    rect(33, 49, 1, 9);
    rect(54, 49, 1, 16);
    rect(152, 49, 8, 1);
    rect(55, 51, 27, 1);
    rect(83, 51, 26, 1);
    rect(110, 51, 9, 1);

    rect(9, 54, 9, 1);
    rect(43, 54, 1, 11);
    rect(9, 55, 1, 6);
    rect(15, 55, 1, 11);
    rect(141, 56, 19, 1);
    rect(28, 57, 5, 1);
    rect(28, 58, 1, 32);
    rect(64, 58, 35, 1);
    rect(108, 58, 21, 1);
    rect(64, 59, 1, 13);
    rect(98, 59, 1, 5);
    rect(108, 59, 1, 16);
    rect(10, 60, 2, 1);
    rect(36, 61, 1, 35);
    rect(136, 61, 18, 1);
    rect(136, 62, 1, 4);
    rect(153, 62, 1, 14);
    rect(72, 63, 26, 1);
    rect(44, 64, 10, 1);
    rect(6, 65, 9, 1);
    rect(119, 65, 17, 1);
    rect(119, 66, 1, 16);
    rect(72, 67, 27, 1);
    rect(143, 67, 10, 1);
    rect(72, 68, 1, 10);
    rect(143, 68, 1, 6);
    rect(5, 69, 17, 1);
    rect(5, 70, 1, 10);
    rect(21, 70, 1, 20);
    rect(37, 71, 27, 1);
    rect(125, 73, 18, 1);
    rect(86, 74, 22, 1);
    rect(125, 74, 1, 15);
    rect(86, 75, 1, 42);
    rect(152, 75, 1, 6);
    rect(154, 75, 6, 1);
    rect(45, 77, 27, 1);
    rect(45, 78, 1, 18);
    rect(6, 79, 11, 1);
    rect(16, 80, 1, 16);
    rect(150, 80, 2, 1);
    rect(95, 81, 24, 1);
    rect(150, 81, 1, 35);
    rect(95, 82, 1, 42);
    rect(58, 84, 1, 12);
    rect(63, 85, 1, 11);
    rect(0, 87, 10, 1);
    rect(9, 88, 1, 15);
    rect(102, 88, 23, 1);
    rect(22, 89, 6, 1);
    rect(102, 89, 1, 44);
    rect(109, 94, 19, 1);
    rect(10, 95, 6, 1);
    rect(17, 95, 19, 1);
    rect(46, 95, 12, 1);
    rect(64, 95, 22, 1);
    rect(109, 95, 1, 21);
    rect(127, 95, 1, 32);
    rect(10, 100, 66, 1);
    rect(75, 101, 1, 7);
    rect(0, 102, 9, 1);
    rect(115, 102, 7, 1);
    rect(121, 103, 1, 13);
    rect(10, 107, 65, 1);
    rect(10, 108, 1, 11);
    rect(33, 108, 1, 4);
    rect(128, 109, 12, 1);
    rect(42, 112, 1, 5);
    rect(110, 115, 11, 1);
    rect(143, 115, 7, 1);
    rect(16, 116, 26, 1);
    rect(43, 116, 43, 1);
    rect(143, 116, 1, 17);
    rect(64, 117, 1, 2);
    rect(6, 118, 4, 1);
    rect(76, 120, 1, 4);
    rect(10, 123, 35, 1);
    rect(49, 123, 27, 1);
    rect(77, 123, 18, 1);
    rect(10, 124, 1, 12);
    rect(44, 124, 1, 15);
    rect(49, 124, 1, 28);
    rect(103, 126, 24, 1);
    rect(58, 130, 24, 1);
    rect(58, 131, 1, 14);
    rect(81, 131, 1, 8);
    rect(87, 131, 1, 14);
    rect(88, 132, 14, 1);
    rect(144, 132, 16, 1);
    rect(11, 134, 24, 1);
    rect(0, 135, 1, 1);
    rect(7, 135, 3, 1);
    rect(34, 135, 1, 17);
    rect(65, 138, 16, 1);
    rect(107, 138, 39, 1);
    rect(107, 139, 1, 5);
    rect(145, 139, 1, 6);
    rect(6, 140, 28, 1);
    rect(21, 141, 1, 7);
    rect(86, 143, 1, 2);
    rect(92, 143, 15, 1);
    rect(6, 144, 4, 1);
    rect(59, 144, 27, 1);
    rect(144, 144, 1, 3);
    rect(146, 144, 14, 1);
    rect(9, 145, 1, 7);
    rect(58, 148, 12, 1);
    rect(74, 148, 64, 1);
    rect(58, 149, 1, 8);
    rect(69, 149, 1, 11);
    rect(74, 149, 1, 11);
    rect(98, 149, 1, 5);
    rect(137, 149, 1, 5);
    rect(10, 151, 24, 1);
    rect(35, 151, 14, 1);
    rect(17, 152, 1, 5);
    rect(99, 153, 38, 1);
    rect(138, 153, 8, 1);
    rect(144, 154, 1, 6);
    rect(26, 156, 1, 4);
    rect(48, 156, 10, 1);
    rect(48, 157, 1, 3);
}
// fase 1
void draw_maze1() {
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

int x, y, ganhou, temChave, nivel, frame, prologo, tempoGasto, tempo, portao, iniX, iniY, esquerda, cima;
char message[] = "Escape the\nlabyrinth...\0\0\0\0\0";
char buffer[120];
ulong current_len = 0;

// inicializa o jogo inteiro, iniciando o nivel em 1, nao tem chave e variaveis dos inimigos
void start() {
    PALETTE[0] = 0xcccec7;
    PALETTE[1] = 0x77746f;
    PALETTE[2] = 0xe53d00;
    PALETTE[3] = 0x2e2622;

    x = 5;
    y = 5;
    temChave = 0;
    nivel = 0;
    frame = 0;
    prologo = 0;
    portao = 145;
    iniX = 142;
    esquerda = 1;
    iniY = 115;
    cima = 1;
}

void update() {
    frame++;
    int dx = 0, dy = 0;
    uint8_t gamepad = *GAMEPAD1;
    if (nivel != 0){
        if (gamepad & BUTTON_LEFT)  { dx -= 1; }
        if (gamepad & BUTTON_RIGHT) { dx += 1; }
        if (gamepad & BUTTON_UP)    { dy -= 1; }
        if (gamepad & BUTTON_DOWN)  { dy += 1; }

    }
    x += dx;
    y += dy;
    Shape player = {x, y, 2, 2};
    // informações do nivel 0, aqui começamos a tela inicial e explicamos a movimentação
    if (nivel == 0) {
        if (gamepad & BUTTON_1) {prologo++;}
        if (prologo == 0){
            *DRAW_COLORS = 4;
            text("LABYRINTH", 45, 50);
            *DRAW_COLORS = 2;
            text("Move using", 25, 70);
            text("  \x86 \n \x84\x87\x85", 105, 65);

            if ((frame / 30) % 2 == 0){
                *DRAW_COLORS = 2;
            }
            else{
                *DRAW_COLORS = 4;
            }

            text("press \x80 to start!", 15, 100);
    }
        else{
            if (frame % TYPE_SPEED == 0 && current_len < sizeof(message) - 1) {
                current_len++;
            }
            for (ulong i = 0; i < current_len; i++) {
                buffer[i] = message[i];
            }
            *DRAW_COLORS = 4;
            text(buffer, 20, 30);
            if (current_len == sizeof(message) - 1) {nivel++; tempoGasto = frame;}
        }
    }

    // aqui iniciamos o nivel 1, definimos a posicao da chave e suas hitsbox
    if(nivel == 1){
        Shape chave_item = {124, 122, 9, 10};
        Shape detecta = {145, 146, 20, 20};
        draw_maze1();

        // abre o portao se o player tem a chave, faz a animaçãozinha dele abrindo ihuu
        if(temChave){
            if (portao < 157){
                if ((frame / 40) % 4 == 0){
                    portao++;
                }
            }
        }
        rect(143, portao, 2, 12);

        // seta que indica onde o player tem que chegar, ela fica indo pro lado e pro outro
        *DRAW_COLORS = 2;
        if ((frame / 25) % 2 == 0){
            text(">", 151 , 150);
        } else {
            text(">", 153, 150);
        }
        // desenha a chave no lugar 
        if (!temChave){
            *DRAW_COLORS = 0x4320;
            blit(chave, 124, 122, 9, 10, BLIT_2BPP);
        }
        // hitboxs pra ver se o player pega a chave, e/ou passa de fase, incrementa o nivel e desenaha prox fase
        if (hit_box_box(player, chave_item)) {temChave = 1;}

        if (hit_box_box(player, detecta) && temChave) {
            nivel++;
            x = y = 5;
            temChave = 0;
            portao = 147;
        }

    }

    if (nivel == 2) {
        // aqui começa a ter inimigos, entao fazemos ele e sua hitbox, ele se movimenta frequentemente, por isso fizemos uma variavel iniX (explicação doq ela faz mais pra baixo)
        Shape chave_item = {44, 53, 9, 10};
        Shape detecta = {145, 146, 20, 20};
        Shape inimigo = {iniX, 145, 3, 3};

        draw_maze2();

        if(temChave){
            if (portao < 157){
                if ((frame / 40) % 4 == 0){
                    portao++;
                }
            }
        }
        rect(144, portao, 1, 10);

        *DRAW_COLORS = 2;
        if ((frame / 25) % 2 == 0){
            text(">", 151 , 150);
        } else {
            text(">", 153, 150);
        }

        if (!temChave){
            *DRAW_COLORS = 0x4320;
            blit(chave, 44, 53, 9, 10, BLIT_2BPP);
        }
        // movimentação do inimigo, iniX fica decrementando e incrementando, assim mudando sua posição enquanto os frames passam
        if (iniX > 57 && esquerda){
                iniX--;
            if (iniX == 57){esquerda = 0;}
        }
        else {
                iniX++;
            if (iniX == 140){esquerda = 1;}
        }

        *DRAW_COLORS = 3;
        rect(iniX, 145, 3, 3);
        // se o player encosta no inimigo, recomeça tudo, perde a chave, portao fecha e volta pro inicio
        if (hit_box_box(player, inimigo)) {temChave = 0; x = y = 5;portao=147;}

        if (hit_box_box(player, chave_item)) {temChave = 1;}

        if (hit_box_box(player, detecta) && temChave) {
            nivel++;
            x = y = 5;
            temChave = 0;
            portao = 13;
            iniX = 158;
        }

    }

    if (nivel == 3) {
        // dois inimigos agora, só que um deles anda no eixo Y, então fizemos o iniY
        Shape chave_item = {40, 72, 9, 10};
        Shape detecta = {145, 146, 20, 20};
        Shape inimigo = {iniX, 115, 2, 2};
        Shape inimigo2 = {155, iniY, 2, 2};
        draw_maze3();

        if(temChave){
            if (portao > 0){
                if ((frame / 40) % 4 == 0){
                    portao--;
                }
            }
        }
        rect(148, 146, (uint32_t)portao, 1);

        *DRAW_COLORS = 2;
        if ((frame / 25) % 2 == 0){
            text(">", 151 , 150);
        } else {
            text(">", 153, 150);
        }

        if (!temChave){
            *DRAW_COLORS = 0x4320;
            blit(chave, 40, 72, 9, 10, BLIT_2BPP);
        }

        if (iniX > 154 && esquerda){
            if (frame % 4 == 0){iniX--;}
            if (iniX == 154){esquerda = 0;}
        } else {
            if (frame  % 4 == 0){iniX++;}
            if (iniX == 160){esquerda = 1;}
        }

        if (iniY > 39 && cima){
                iniY--;
            if (iniY == 39){cima = 0;}
        }
        else {
                iniY++;
            if (iniY == 144){cima = 1;}
        }


        *DRAW_COLORS = 3;
        rect(iniX, 115, 2, 2);
        rect(155, iniY, 2, 2);

        if (hit_box_box(player, inimigo) || (hit_box_box(player, inimigo2))) {temChave = 0; x = y = 5;portao=15;}

        if (hit_box_box(player, chave_item)) {temChave = 1;}

        if (hit_box_box(player, detecta) && temChave) {
            nivel++;
            temChave = 0;
            tempo = (frame - tempoGasto) / 60;
        }

    }

    if (nivel >  0 && nivel < 4){
        if (pget(x,   y  ) == 4 ||
            pget(x+1, y  ) == 4 ||
            pget(x,   y+1) == 4 ||
            pget(x+1, y+1) == 4 ||
            x > 159 || x < 0    ||
            y > 159 || y < 0) {
            x -= dx;
            y -= dy;
        }

        *DRAW_COLORS = 2;
        rect(x, y, 2, 2);
    }
    // assim, quando o player acaba o jogo, contamos quanto tempo ele levou para passar das 3 fases, thats it!
    if (nivel > 3){
        *DRAW_COLORS = 2;
        char buf[10];
        itoa(buf, tempo);
        text("YOU WON!!", 40, 50);
        text("Took you: ", 5, 70);
        text(buf, 80, 70);
        text("secs!", 110, 70);
    }
}
