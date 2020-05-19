#ifndef _GAME_H_
#define _GAME_H_
#include "point.h"
#include "helper.h"
#include "board_drawer.h"

/*! \fn int change_state(Point p, short field[_size][_size]);
 * \brief Change state of given Point on a given field
 * \param p - given point to change
 * \param field - game area
 * \return 1 - success
*/ 
int change_state(Point p, short field[_size][_size]);
/*! \fn int kill(Point p, short field[_size][_size]);
 * \brief Change state of given Point to 0
 * \param p - given point to change
 * \param field - game area
 * \return 1 - success
*/ 
int kill(Point p, short field[_size][_size]);
/*! \fn int born(Point p, short field[_size][_size]);
 * \brief Change state of given Point to 1
 * \param p - given point to change
 * \param field - game area
 * \return 1 - success
*/ 
int born(Point p, short field[_size][_size]);
/*!
 * \fn void start_game(int stages ,short field[_size][_size], int version);
 * \brief Starts the game
 * \param stages - number of stages
 * \param field - game area
 * \param version - game version
 * \return void
*/ 
void start_game(int stages ,short field[_size][_size], int version);
/*!
 * \fn void next_stage(short field[_size][_size], int version);
 * \brief Change field to the next stage
 * \param field - game area
 * \param version - game version
 * \return void
*/ 
void next_stage(short field[_size][_size], int version);


#endif