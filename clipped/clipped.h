#ifndef _CLIPPED_H_
#define _CLIPPED_H_
#include "point.h"
/*
 * Calculate number of live neighbors of the given point in clipped version
 * Arguments:
 *      p - given point
 *      field - game field
 * Return: (int) number of neighbors 
 */  
int clipped_live_neighbors(Point p, short field[_size][_size]); 


#endif