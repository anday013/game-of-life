#ifndef _GAME_H_
#define _GAME_H_
#include "point.h"


void change_state(Point p, short field[SIZE][SIZE]);
void kill(Point p, short field[SIZE][SIZE]);
void born(Point p, short field[SIZE][SIZE]);
void start_game(int stages ,short field[SIZE][SIZE]);
void next_stage(short field[SIZE][SIZE]);


#endif