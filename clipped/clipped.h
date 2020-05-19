#ifndef _CLIPPED_H_
#define _CLIPPED_H_
#include "point.h"
/*! \fn int clipped_live_neighbors(Point p, short field[_size][_size])
 *  \brief Calculate number of live neighbors of the given point in clipped version
 *  \param p - given point
 *  \param field - game field
 *  \return number of alive neighbors 
 */ 
int clipped_live_neighbors(Point p, short field[_size][_size]); 


#endif