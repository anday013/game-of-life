#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define MAX_NEIGHBORS 8

struct Point{
    int row;
    int col;
}typedef Point;


int live_neighbors(Point p, int field[SIZE][SIZE]);
int shouldDie(Point p, int field[SIZE][SIZE]);
int shouldLive(Point p, int field[SIZE][SIZE]);

#endif