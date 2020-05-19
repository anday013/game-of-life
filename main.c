#include "point.h"
#include "game.h"
#include "helper.h"
#include "sdl.h"
#include <time.h> 
#include <string.h>

void consoleVersionActions(short field[_size][_size], int version);
void main(int args, char **argv)
{
    _size = 20; // Initial game field size
    // Geting version from player(circular or clipped)
    int version = get_version();
    // Getting game type from player(sdl or console)
    int game_type = get_game_type();
    
    short field[_size][_size]; // Game area
    initialize_field(field);

    if (game_type == 0) // If console version selected
        consoleVersionActions(field, version);
    else
        sdl_run();
    
}


void consoleVersionActions(short field[_size][_size], int version){
    Point points1[] = {create_point(0, 0), create_point(1, 0), create_point(2, 0)}; // Points to draw
    int points1_length = sizeof points1 / sizeof points1[0]; // Finding array length
    locate_points(points1, points1_length, field);

    Point points2[] = {create_point(9,9), create_point(9,10), create_point(10,9), create_point(10,10)};
    int points2_length = sizeof points2 / sizeof points2[0]; // Finding array length
    locate_points(points2, points2_length, field);

    Point points3[] = {create_point(5,5), create_point(4,5), create_point(6,5)};
    int points3_length = sizeof points3 / sizeof points3[0]; // Finding array length
    locate_points(points3, points3_length, field);


    int stages = get_stages();
    start_game(stages, field, version);
}