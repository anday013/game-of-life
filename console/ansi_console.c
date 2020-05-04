#include "board_drawer.h"

void draw_field(short field[SIZE][SIZE])
{
    // clear screen
    printf("\033[2J");
    // hide cursor
	printf("\033[?25l");
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (field[r][c])
                printf("\033[%dm ", 104);
            else
                printf("\033[%dm ", 41);
        }
        printf("\n");
    }
    usleep(150000);
}