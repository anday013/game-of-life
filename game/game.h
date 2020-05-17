#ifndef _GAME_H_
#define _GAME_H_
#include "point.h"
#include "helper.h"
#include "board_drawer.h"

/*
 * Change state of given Point on a given field
 * Arguments:
 *      p - given point to change
 *      field - game area
 * Return: 1 - success
*/ 
int change_state(Point p, short field[_size][_size]);
/*
 * Change state of given Point to 0
 * Arguments:
 *      p - given point to change
 *      field - game area
 * Return: 1 - success
*/ 
int kill(Point p, short field[_size][_size]);
/*
 * Change state of given Point to 1
 * Arguments:
 *      p - given point to change
 *      field - game area
 * Return: 1 - success
*/ 
int born(Point p, short field[_size][_size]);
/*
 * Starts the game
 * Arguments:
 *      stages - number of stages
 *      field - game area
 *      version - game version
 * Return: void
*/ 
void start_game(int stages ,short field[_size][_size], int version);
/*
 * Change field to the next stage
 * Arguments:
 *      field - game area
 *      version - game version
 * Return: void
*/ 
void next_stage(short field[_size][_size], int version);


#endif