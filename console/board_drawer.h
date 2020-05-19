#ifndef _BOARD_H_
#define _BOARD_H_
#include "point.h"
#include "unistd.h"

/*! \fn void draw_field(short field[_size][_size])
 *  \brief Draw table on console
 *  \param field - game field
 *  \return void
 */    
void draw_field(short field[_size][_size]);


#endif

