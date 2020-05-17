#include "point.h"

int check_point(Point p, int rows, int cols)
{
    if (p.col < cols && p.row < rows)
        return 1;
    printf("Point ( %d, %d ) does not belong to game board\n", p.row, p.col);
    return 0;
}

Point create_point(int row, int col)
{
    Point p = {row, col};
    if (check_point(p, _size, _size))
        return p;
    perror("Point creation failed...");
    exit(0);
}

int alive_or_dead(Point p, short field[_size][_size])
{
    return field[p.row][p.col];
}

int is_critical(Point p)
{
    if (check_point(p, _size, _size))
        return p.row == LIMIT || p.row == 0 || p.col == LIMIT || p.col == 0;
    return 0;
}

int live_neighbors(Point p, short field[_size][_size], int version)
{
    int alive = 0;
    if (is_critical(p))
    {
        if (version == 1)
            alive = clipped_live_neighbors(p, field);
        else
            alive = circular_live_neighbors(p, field);
    }
    else
    {
        int neighbors[] = {
            field[p.row - 1][p.col],
            field[p.row + 1][p.col],
            field[p.row][p.col + 1],
            field[p.row][p.col - 1],
            field[p.row - 1][p.col - 1],
            field[p.row - 1][p.col + 1],
            field[p.row + 1][p.col + 1],
            field[p.row + 1][p.col - 1],
        };
        for (int i = 0; i < MAX_NEIGHBORS; i++)
            if (neighbors[i])
                alive++;
    }

    return alive;
}

int live_or_die(Point p, short field[_size][_size], int version)
{
    int live_nghbrs = live_neighbors(p, field, version);
    if (field[p.row][p.col])
        return live_nghbrs == 3 || live_nghbrs == 2;
    else
        return live_nghbrs == 3;
}