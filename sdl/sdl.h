#ifndef _SDL_H_
#define _SDL_H_
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "helper.h"
#include "point.h"
int _window_size; // Global window size variable
#define SCALE _window_size / _size // Relation between window size and table size
/*!
 * \fn void draw(SDL_Renderer *renderer, short field[_size][_size]);
 * \brief Draw table on window
 * \param renderer - sdl renderer
 * \param field - game table
 * \return void
*/ 
void draw(SDL_Renderer *renderer, short field[_size][_size]);
/*!
 * \fn int get_size(char *object);
 * \brief Get size from user
 * \param object - name of object
 * \return (int) size
*/ 
int get_size(char *object);
/*!
 * \fn void game_run();
 * \brief game start
 * \param renderer - sdl renderer
 * \param field - game table
 * \param version - game version
 * \return void
*/ 
void game_run();
/*!
 * \fn void window_reset(SDL_Renderer *renderer, short field[_size][_size]);
 * \brief Clear table and set background to black
 * \param renderer - sdl renderer
 * \param field - game table
 * \return void
*/ 
void window_reset(SDL_Renderer *renderer, short field[_size][_size]);
/*!
 * \fn void mouse_listener(SDL_Renderer *renderer, short field[_size][_size], bool isActive);
 * \brief Stands for mouse actions
 * \param renderer - sdl renderer
 * \param field - game table
 * \param isActive - should work
 * \return void
*/ 
void mouse_listener(SDL_Renderer *renderer, short field[_size][_size], bool isActive);
/*!
 * \fn
 * \brief Sdl entry point
 * \param version - game version
 * \return void
*/ 
void sdl_run();

#endif