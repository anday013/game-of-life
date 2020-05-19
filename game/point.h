#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>
#include <stdlib.h>

int _size;
#define LIMIT (_size - 1)
#define MAX_NEIGHBORS 8
#define CLIPPED_NEIGHBORS 5
/*! 
 * \struct Point
 * \brief Game cell on board
 */
struct Point
{
    int row;
    int col;
} typedef Point;

#include "circular.h"
#include "clipped.h"
/*!
 * \fn Point create_point(int row, int col);
 * \brief Create point
 * \param row - point row
 * \param col - point column
 * \return (Point stucture) created point
*/ 
Point create_point(int row, int col);
/*!
 * \fn int check_point(Point p, int rows, int cols);
 * \brief Check point
 * \param p - point to check
 * \param rows,cols - table size
 * \return 1 - everything OK, otherwise 0 
*/ 
int check_point(Point p, int rows, int cols);
/*!
 * \fn int is_critical(Point p);
 * \brief Check point for critical (on the border)
 * \param p - point to check
 * \return 1 - yes  0 - no 
*/ 
int is_critical(Point p);
/*!
 * \fn int live_neighbors(Point p, short field[_size][_size], int version);
 * \brief Find live neighbors
 * \param p - point to find
 * \param field - game table
 * \param version - game version
 * \return Number of live neighbors
*/ 
int live_neighbors(Point p, short field[_size][_size], int version);
/*!
 * \fn int alive_or_dead(Point p, short field[_size][_size]);
 * \brief Check point for life 
 * \param p - point to check
 *  \param field - game table
 * \return 1 - alive  0 - dead 
*/ 
int alive_or_dead(Point p, short field[_size][_size]);
/*!
 * \fn int live_or_die(Point p, short field[_size][_size], int version);
 * \brief Should point live or die on next day
 * \param p - point to check
 * \param field - game table
 * \param version - game version
 * \return 1 - yes  0 - no 
*/ 
int live_or_die(Point p, short field[_size][_size], int version);

#endif