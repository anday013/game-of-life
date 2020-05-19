#ifndef _HELPER_H_
#define _HELPER_H_

#include "point.h"
#include "game.h"
#include <string.h>

#define FAIL_IF_MSG(EXP, MSG) ({if(EXP){printf(MSG "\n"); exit(EXIT_FAILURE);} })
/*! \fn int get_game_type();
 * \brief Get game type from player (sdl or console)
 * \return 0 - console , 1 - SDL
 */
int get_game_type();
/*! \fn int get_version();
 * \brief Get game version from player (clipped or circular)
 * \return 0 - circular , 1 - clipped
 */
int get_version();
/*! \fn int get_stages();
 * \brief Get number of stages in console game
 * \return number of stages
 */
int get_stages();
/*! \fn int initialize_field(short field[_size][_size]);
 * \brief Set all table cells to 0
 * \param field the game field
 * \return 1 - success
 */
int initialize_field(short field[_size][_size]);
/*! \fn int locate_points(Point points[], int length, short field[_size][_size]);
 * \param points a set of point to locate
 * \param length a size of points array
 * \param field the game field
 * \brief Locate inital alive point on table
 * \return 1 - success
 */
int locate_points(Point points[], int length, short field[_size][_size]);
/*! \fn int copy_field(short src_field[_size][_size], short new_field[_size][_size]);
 * \param src_field a source array
 * \param new_field a new array
 * \brief Copy 2d arrays
 * \return 1 - success
 */
int copy_field(short src_field[_size][_size], short new_field[_size][_size]);

#endif