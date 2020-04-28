#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define LIMIT (SIZE - 1)
#define MAX_NEIGHBORS 8

struct Point
{
    int row;
    int col;
} typedef Point;

Point create_point(int row, int col);
int check_point(Point p, int rows, int cols);
int live_neighbors(Point p, short field[SIZE][SIZE]);
int clipped_live_neighbors(Point p, short field[SIZE][SIZE]); // Different for versions
int alive_or_dead(Point p, short field[SIZE][SIZE]);           // alive - 1 dead - 0
int shouldDie(Point p, short field[SIZE][SIZE]);
int shouldLive(Point p, short field[SIZE][SIZE]);

#endif