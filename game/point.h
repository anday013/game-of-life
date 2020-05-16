#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>

int _size;
#define LIMIT (_size - 1)
#define MAX_NEIGHBORS 8
#define CLIPPED_NEIGHBORS 5

struct Point
{
    int row;
    int col;
} typedef Point;

#include "circular.h"
#include "clipped.h"
/*
 * Create point
 * Argument: 
 * 		row - point row
 * 		col - point column
 * Return: (Point stucture) created point
*/ 
Point create_point(int row, int col);
/*
 * Check point
 * Argument: 
 *      p - point to check
 * 		rows, cols - table size
 * Return: 1 - everything OK, otherwise 0 
*/ 
int check_point(Point p, int rows, int cols);
/*
 * Check point for critical (on the border)
 * Argument: 
 *      p - point to check
 * Return: 1 - yes  0 - no 
*/ 
int is_critical(Point p);
/*
 * Find live neighbors
 * Argument: 
 *      p - point to find
 *      field - game table
 *      version - game version
 * Return: Number of live neighbors
*/ 
int live_neighbors(Point p, short field[_size][_size], int version);
/*
 * Check point for life 
 * Argument: 
 *      p - point to check
 *      field - game table
 * Return: 1 - alive  0 - dead 
*/ 
int alive_or_dead(Point p, short field[_size][_size]);
/*
 * Should point live or die on next day
 * Argument: 
 *      p - point to check
 *      field - game table
 *      version - game version
 * Return: 1 - yes  0 - no 
*/ 
int live_or_die(Point p, short field[_size][_size], int version);

#endif