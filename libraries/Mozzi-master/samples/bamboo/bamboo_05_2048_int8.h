#ifndef BAMBOO_05_2048_H_
#define BAMBOO_05_2048_H_

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"

#define BAMBOO_05_2048_NUM_CELLS 2048
#define BAMBOO_05_2048_SAMPLERATE 16384

CONSTTABLE_STORAGE(int8_t) BAMBOO_05_2048_DATA []  = {1, 0, 1, -1, 0, -1, 0, -1, 0, 0, 0,
1, 0, 0, 0, 1, -1, 0, -2, 0, -2, 1, -1, -1, 1, -1, 1, -1, -1, 2, 0, -14, -68,
-126, -100, 25, 94, 82, 109, 90, -30, -52, 15, 13, -18, -34, -68, -66, -8, 5,
-3, -18, -39, 34, 102, 44, 10, 47, 16, -7, 20, -33, -57, 32, 38, -35, -67, -71,
-69, -6, 60, 17, -16, 5, 6, 8, 10, 43, 74, 41, 15, 4, -26, -38, 5, 12, -49, -53,
-9, -23, -35, -20, -18, 1, 36, 35, 16, 28, 39, 24, 18, 7, 1, 5, 4, -2, -30, -69,
-59, -3, 4, -11, -7, -17, -23, 13, 33, 27, 33, 39, 29, 18, 8, 1, 2, 0, -11, -23,
-44, -46, -30, -25, -20, -5, -5, -7, 12, 27, 26, 33, 36, 20, 11, 19, 14, -7,
-19, -23, -22, -21, -25, -27, -25, -23, -19, -7, 6, 19, 28, 24, 22, 21, 17, 17,
25, 17, -3, -13, -23, -36, -31, -22, -15, -17, -21, -23, -12, 1, 20, 28, 25, 25,
29, 22, 17, 10, 0, -4, 0, -8, -23, -29, -25, -24, -26, -20, -17, -4, 14, 23, 18,
13, 21, 28, 32, 26, 15, -5, -16, -19, -23, -18, -17, -23, -27, -20, -9, -3, 1,
9, 14, 16, 21, 21, 13, 6, 19, 19, 4, -1, -8, -17, -19, -23, -24, -28, -23, -9,
-9, -5, 3, 14, 14, 20, 28, 24, 20, 17, 4, -5, -4, -6, -14, -24, -24, -25, -26,
-22, -14, -9, 2, 16, 22, 16, 18, 22, 19, 19, 16, 5, -8, -6, -4, -14, -25, -23,
-26, -22, -9, -10, -10, -2, 7, 12, 20, 23, 18, 19, 17, 12, 5, -1, -7, -9, -16,
-20, -23, -26, -24, -12, -5, 0, 4, 2, 11, 22, 25, 18, 12, 10, 12, 9, 3, -8, -15,
-16, -17, -24, -27, -22, -16, -4, 1, 0, 7, 16, 23, 23, 19, 12, 12, 11, 3, -2,
-10, -14, -18, -20, -22, -20, -17, -12, -8, -3, 4, 15, 20, 18, 17, 18, 14, 15,
11, -3, -7, -7, -13, -22, -24, -24, -17, -11, -9, -11, -5, 7, 17, 16, 15, 16,
15, 15, 15, 8, 0, -3, -5, -14, -21, -20, -19, -21, -16, -14, -8, 3, 10, 8, 12,
16, 19, 16, 16, 13, 10, 4, -4, -13, -20, -17, -15, -17, -22, -18, -11, -7, 3, 8,
9, 11, 18, 19, 16, 14, 13, 9, 4, -2, -14, -19, -18, -17, -18, -19, -19, -14, -5,
6, 8, 8, 15, 20, 22, 15, 14, 10, 7, 1, -7, -16, -16, -16, -16, -23, -23, -14,
-7, -1, 2, 4, 8, 13, 20, 16, 14, 14, 15, 8, -2, -8, -12, -13, -13, -18, -26,
-23, -12, -6, -5, -1, 3, 12, 17, 21, 17, 13, 14, 15, 8, -4, -10, -10, -12, -17,
-23, -24, -17, -9, -5, -4, 2, 6, 11, 16, 20, 18, 14, 12, 9, 2, -1, -5, -8, -14,
-17, -22, -22, -15, -10, -5, -4, 1, 7, 12, 14, 15, 16, 14, 15, 10, 2, -3, -7,
-8, -14, -19, -21, -19, -13, -8, -7, -7, -1, 7, 15, 14, 14, 14, 14, 10, 7, 2,
-1, -2, -6, -15, -20, -20, -16, -12, -8, -8, -5, 1, 6, 8, 12, 17, 16, 13, 10, 4,
4, 1, -6, -13, -17, -17, -12, -11, -14, -12, -9, -2, 3, 6, 8, 13, 16, 15, 13,
10, 7, 7, 0, -7, -16, -18, -16, -14, -12, -14, -11, -6, 0, 2, 7, 11, 10, 16, 13,
10, 7, 6, 5, -2, -8, -12, -14, -11, -12, -15, -15, -10, -5, 0, 3, 7, 9, 13, 15,
12, 9, 10, 10, 5, -2, -10, -13, -12, -12, -11, -14, -13, -9, -3, -2, 2, 7, 9,
13, 13, 9, 9, 7, 7, 2, -2, -7, -10, -12, -13, -16, -15, -11, -6, -6, -1, 2, 7,
10, 11, 13, 13, 11, 8, 3, -1, -6, -5, -8, -13, -14, -15, -13, -10, -8, -4, 1, 6,
9, 9, 11, 10, 9, 8, 8, 4, -1, -3, -8, -9, -11, -12, -13, -11, -10, -8, -5, -1,
2, 7, 9, 13, 12, 12, 7, 7, 1, 0, -1, -8, -11, -13, -14, -14, -11, -10, -5, -1,
1, 5, 8, 8, 9, 12, 10, 9, 5, 2, 0, -3, -8, -9, -11, -13, -12, -8, -10, -7, -3,
2, 5, 8, 10, 10, 11, 10, 8, 3, 1, -2, -5, -8, -9, -13, -13, -11, -9, -8, -5, -1,
3, 4, 8, 10, 11, 10, 10, 7, 5, 1, 0, -5, -8, -11, -11, -12, -10, -9, -7, -4, 1,
2, 6, 7, 8, 10, 10, 9, 4, 3, 0, -1, -5, -7, -9, -13, -11, -11, -9, -9, -4, -1,
3, 6, 6, 7, 7, 9, 10, 7, 3, 0, -2, -4, -6, -11, -11, -12, -9, -9, -6, -4, -1, 2,
7, 7, 8, 9, 8, 9, 6, 2, -1, -5, -4, -7, -11, -11, -12, -8, -8, -7, -2, -1, 3, 5,
7, 8, 10, 7, 6, 4, 3, 0, -4, -5, -8, -10, -11, -9, -9, -8, -5, -2, 1, 3, 5, 7,
7, 10, 9, 5, 4, 3, 0, -3, -6, -7, -9, -10, -9, -10, -7, -6, -2, 1, 2, 5, 6, 9,
8, 8, 5, 4, 3, 2, -3, -6, -10, -9, -11, -9, -10, -7, -4, -4, 1, 3, 6, 8, 9, 6,
6, 5, 5, 2, -1, -4, -6, -7, -8, -10, -10, -9, -6, -4, -2, 0, 3, 6, 8, 7, 5, 4,
5, 3, 2, -1, -4, -6, -7, -9, -9, -9, -7, -5, -3, -2, -1, 1, 5, 6, 5, 6, 7, 4, 3,
1, -1, -3, -5, -7, -8, -9, -8, -8, -6, -3, 0, 0, 3, 4, 6, 6, 7, 5, 5, 2, 0, -2,
-3, -6, -7, -9, -9, -7, -6, -5, -3, -1, 1, 4, 5, 4, 5, 7, 6, 4, 1, -1, -2, -3,
-5, -7, -8, -7, -6, -6, -5, -3, -1, 1, 3, 4, 4, 5, 6, 6, 3, 1, -1, -2, -3, -5,
-8, -7, -7, -8, -7, -5, -2, 0, 1, 2, 4, 5, 6, 6, 4, 3, 1, 1, -1, -4, -6, -7, -6,
-7, -7, -7, -4, -1, 0, 1, 3, 4, 5, 6, 6, 4, 2, 1, 0, -3, -4, -6, -7, -7, -7, -7,
-6, -3, -1, 0, 1, 3, 4, 5, 5, 4, 4, 3, 1, -1, -3, -4, -5, -5, -6, -6, -6, -5,
-3, -1, 0, 1, 2, 5, 5, 5, 4, 3, 2, 1, 0, -3, -4, -5, -6, -5, -6, -5, -4, -3, -1,
0, 1, 3, 3, 4, 4, 3, 3, 3, 0, -2, -3, -4, -5, -5, -5, -6, -5, -4, -3, -1, 0, 1,
3, 4, 3, 3, 3, 3, 2, 0, -1, -3, -4, -4, -6, -6, -5, -4, -4, -3, -1, 0, 1, 2, 3,
4, 4, 3, 3, 1, 0, -2, -3, -4, -4, -5, -5, -5, -5, -3, -2, -1, 0, 2, 2, 3, 3, 3,
3, 3, 2, 0, -1, -3, -3, -5, -4, -5, -5, -4, -4, -2, -1, 0, 2, 2, 3, 4, 4, 2, 1,
1, 0, -1, -3, -4, -5, -5, -4, -4, -4, -3, -2, -1, 1, 1, 2, 3, 4, 3, 2, 2, 1, 0,
-1, -3, -3, -4, -5, -5, -5, -4, -3, -2, 0, 1, 2, 2, 3, 3, 2, 3, 2, 1, 0, -2, -3,
-4, -5, -4, -4, -4, -4, -3, -1, -1, 0, 2, 2, 2, 3, 2, 2, 1, 0, 0, -2, -3, -3,
-4, -5, -5, -4, -3, -3, -2, -1, 0, 2, 2, 3, 3, 2, 2, 2, 0, -1, -2, -2, -3, -4,
-4, -4, -4, -3, -2, -1, -1, 0, 1, 2, 2, 3, 2, 1, 1, 0, 0, -2, -2, -3, -4, -4,
-4, -4, -3, -2, -1, 0, 1, 1, 2, 2, 2, 1, 1, 1, 0, -1, -2, -2, -3, -4, -4, -4,
-3, -2, -2, -1, 0, 1, 1, 2, 1, 3, 2, 1, 0, 0, -1, -2, -2, -3, -3, -4, -4, -3,
-3, -2, -1, 0, 1, 1, 1, 1, 2, 1, 1, 0, 0, -1, -2, -2, -3, -3, -4, -3, -3, -2,
-2, -1, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, -1, -2, -3, -3, -3, -3, -3, -3, -2, -1,
-1, 0, 0, 1, 1, 1, 2, 1, 1, 0, 0, -1, -2, -3, -3, -3, -3, -3, -3, -2, -2, -1, 0,
1, 1, 1, 1, 1, 1, 1, 0, 0, -2, -2, -3, -3, -3, -3, -3, -2, -2, -2, 0, 0, 1, 1,
1, 1, 1, 1, 1, 0, 0, -2, -2, -2, -3, -3, -3, -3, -3, -2, -1, -1, 0, 0, 1, 1, 2,
1, 1, 0, 0, -1, -1, -1, -2, -2, -2, -2, -2, -2, -1, -1, 0, 0, 0, 1, 1, 1, 1, 0,
0, 0, -1, -1, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 0, 0,
0, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, -1,
-1, -2, -2, -2, -2, -2, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1,
-2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, -1, -1, -2,
-2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, -1, -2, -2, -2,
-2, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -2, -2, -2,
-2, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, };

 #endif /* BAMBOO_05_2048_H_ */
