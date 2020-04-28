#ifndef _GAME_H_
#define _GAME_H_
#include "point.h"


void change_state(Point p, short field[SIZE][SIZE]);
void initialize_field(short field[SIZE][SIZE]);
void print_field(short field[SIZE][SIZE]);


#endif