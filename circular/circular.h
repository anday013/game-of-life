#ifndef _CIRCULAR_H_
#define _CIRCULAR_H_
#include "point.h"
/*! \fn int circular_live_neighbors(Point p, short field[_size][_size])
 *  \brief Calculate number of live neighbors of the given point in circular version
 *  \param p - given point
 *  \param field - game field
 *  \return number of alive neighbors 
 */      
int circular_live_neighbors(Point p, short field[_size][_size]);


#endif