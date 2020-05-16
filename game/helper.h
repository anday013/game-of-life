#ifndef _HELPER_H_
#define _HELPER_H_

#include "point.h"
#include "game.h"
#include <string.h>

#define FAIL_IF_MSG(EXP, MSG) ({if(EXP){printf(MSG "\n"); exit(EXIT_FAILURE);} })

int get_game_type();
int get_version();
int get_stages();
void initialize_field(short field[_size][_size]);
void locate_points(Point points[], int length, short field[_size][_size]);
int copy_field(short src_field[_size][_size], short new_field[_size][_size]);

#endif