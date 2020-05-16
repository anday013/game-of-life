#include "point.h"
#include "game.h"
#include "helper.h"
#include "sdl.h"
#include <string.h>

void main(int args, char **argv)
{
    _size = 20;
    // Geting version from player(circular or clipped)
    int version = get_version();
    // Getting game type from player(sdl or console)
    int game_type = get_game_type();
    
    short field[_size][_size];
    initialize_field(field);

    Point points[] = {create_point(0, 0), create_point(1, 0), create_point(2, 0)};
    int points_length = sizeof points / sizeof points[0];

    locate_points(points, points_length, field);
    if (game_type == 0)
    {
        int stages = get_stages();
        start_game(stages, field, version);
    }
    else
        sdl_run();
    
}
