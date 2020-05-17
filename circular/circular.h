#ifndef _CIRCULAR_H_
#define _CIRCULAR_H_
#include "point.h"
/*
 * Calculate number of live neighbors of the given point in circular version
 * Arguments:
 *      p - given point
 *      field - game field
 * Return: (int) number of neighbors 
 */      
int circular_live_neighbors(Point p, short field[_size][_size]);


#endif