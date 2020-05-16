#include "board_drawer.h"

void draw_field(short field[_size][_size])
{
    printf("\033[2J");

    for (int r = 0; r < _size; r++)
    {
        for (int c = 0; c < _size; c++)
        {
            if (field[r][c])
            {
                printf("\e[104m  ");
            }
            else
            {
                printf("\e[41m  ");
            }
        }
        printf("\e[0m");
        printf("\n");
    }
    usleep(200000);
    printf("\n");
}