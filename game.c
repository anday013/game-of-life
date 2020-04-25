#include "game.h"

void change_state(Point p, short field[SIZE][SIZE])
{
    field[p.row][p.col] = !field[p.row][p.col];
}

void initialize_field(short field[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            field[r][c] = 0;
        }
    }
}

void print_field(short field[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (field[r][c])
                printf("1 | ");
            else
                printf("0 | ");
        }
        printf("\n");
    }
}