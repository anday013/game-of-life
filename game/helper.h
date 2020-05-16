#ifndef _HELPER_H_
#define _HELPER_H_

#include "point.h"
#include "game.h"
#include <string.h>

#define FAIL_IF_MSG(EXP, MSG) ({if(EXP){printf(MSG "\n"); exit(EXIT_FAILURE);} })

void argument_checker(int args, char **argv);
int get_version(int args, char **argv);
int get_stages(int args, char **argv);
void initialize_field(short field[SIZE][SIZE]);
void locate_points(Point points[], int size, short field[SIZE][SIZE]);
int copy_field(short src_field[SIZE][SIZE], short new_field[SIZE][SIZE]);

#endif