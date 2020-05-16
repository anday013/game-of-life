#include "game.h"

void change_state(Point p, short field[SIZE][SIZE])
{
    field[p.row][p.col] = !field[p.row][p.col];
}

void start_game(int stages, short field[SIZE][SIZE], int version)
{
    if (stages != 0)
        while (stages != 0)
        {
            draw_field(field);
            next_stage(field, version);
            stages--;
        }
    else
        while (1)
        {
            draw_field(field);
            next_stage(field, version);
        }
}

void kill(Point p, short field[SIZE][SIZE])
{
    field[p.row][p.col] = 0;
}
void born(Point p, short field[SIZE][SIZE])
{
    field[p.row][p.col] = 1;
}

void next_stage(short field[SIZE][SIZE], int version)
{
    short next_field[SIZE][SIZE];
    copy_field(field, next_field);
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            Point p = create_point(r, c);
            int destiny = live_or_die(p, field, version);
            if (destiny)
                born(p, next_field);
            else
                kill(p, next_field);
        }
    }
    copy_field(next_field, field);
}