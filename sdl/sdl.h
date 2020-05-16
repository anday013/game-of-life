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
/*
 * Draw table on window
 * Argument: 
 * 		renderer - sdl renderer
 * 		field - game table
 * Return: void
*/ 
void draw(SDL_Renderer *renderer, short field[_size][_size]);
/*
 * Get size from user
 * Argument: 
 * 		object - name of object
 * Return: (int) size
*/ 
int get_size(char *object);
/*
 * game start
 * Argument: 
 * 		renderer - sdl renderer
 * 		field - game table
 * 		version - game version
 * Return: void
*/ 
void game_run();
/*
 * Clear table and set background to black
 * Argument: 
 * 		renderer - sdl renderer
 * 		field - game table
 * Return: void
*/ 
void window_reset(SDL_Renderer *renderer, short field[_size][_size]);
/*
 * Stands for mouse actions
 * Argument: 
 * 		renderer - sdl renderer
 * 		field - game table
 * 		isActive - should work
 * Return: void
*/ 
void mouse_listener(SDL_Renderer *renderer, short field[_size][_size], bool isActive);
/*
 * Sdl entry point
 * Argument: 
 * 		version - game version
 * Return: void
*/ 
void sdl_run();

#endif