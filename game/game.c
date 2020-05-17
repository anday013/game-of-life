#include "game.h"

int change_state(Point p, short field[_size][_size])
{
    field[p.row][p.col] = !field[p.row][p.col];
    return 1;
}

void start_game(int stages, short field[_size][_size], int version)
{
    if (stages != 0) // Finite stages
        while (stages != 0)
        {
            draw_field(field);
            next_stage(field, version);
            stages--;
            usleep(500000);
        }
    else // Infinite stages
        while (1)
        {
            draw_field(field);
            next_stage(field, version);
            usleep(500000);
        }
}

int kill(Point p, short field[_size][_size])
{
    field[p.row][p.col] = 0;
    return 1;
}
int born(Point p, short field[_size][_size])
{
    field[p.row][p.col] = 1;
    return 1;
}

void next_stage(short field[_size][_size], int version)
{
    short next_field[_size][_size];
    copy_field(field, next_field);
    for (int r = 0; r < _size; r++)
    {
        for (int c = 0; c < _size; c++)
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