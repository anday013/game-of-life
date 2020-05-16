#ifndef _GAME_H_
#define _GAME_H_
#include "point.h"
#include "helper.h"
#include "board_drawer.h"

void change_state(Point p, short field[_size][_size]);
void kill(Point p, short field[_size][_size]);
void born(Point p, short field[_size][_size]);
void start_game(int stages ,short field[_size][_size], int version);
void next_stage(short field[_size][_size], int version);


#endif