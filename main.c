#include "point.h"
#include "game.h"
#include "helper.h"
#include <string.h>
void main(int args, char **argv)
{
    // Geting version from arguments
    int version = get_version(args, argv);
    // Number of steps for game
    int stages = get_stages(args, argv);
    short field[SIZE][SIZE];
    initialize_field(field);

    Point points[] = {create_point(0, 0), create_point(1, 0), create_point(2, 0)};
    int points_size = sizeof points / sizeof points[0];

    locate_points(points, points_size, field);

    start_game(stages, field, version);
}



