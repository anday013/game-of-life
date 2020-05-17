#ifndef _HELPER_H_
#define _HELPER_H_

#include "point.h"
#include "game.h"
#include <string.h>

#define FAIL_IF_MSG(EXP, MSG) ({if(EXP){printf(MSG "\n"); exit(EXIT_FAILURE);} })
/*
 * Get game type from player (sdl or console)
 * Return: (1 or 0) game type
 */
int get_game_type();
/*
 * Get game version from player (clipped or circular)
 * Return: (1 or 0) game version
 */
int get_version();
/*
 * Get number of stages in console game
 * Return: number of stages
 */
int get_stages();
/*
 * Set all table cells to 0
 * Return: 1 - success
 */
int initialize_field(short field[_size][_size]);
/*
 * Locate inital alive point on table
 * Return: 1 - success
 */
int locate_points(Point points[], int length, short field[_size][_size]);
/*
 * Copy 2d arrays
 * Return: 1 - success
 */
int copy_field(short src_field[_size][_size], short new_field[_size][_size]);

#endif