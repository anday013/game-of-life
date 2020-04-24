#include "point.h"


int live_neighbors(Point p, int field[SIZE][SIZE]){
    int alive = 0;
    if(field[p.row][p.col] != 1) return -1;
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
    for(int i = 0; i < MAX_NEIGHBORS; i++)
        if(neighbors[i]) alive++;
    
    return alive;
}
int shouldDie(Point p, int field[SIZE][SIZE]){
    int live_nghbrs = live_neighbors(p, field);
    return live_nghbrs > 3 || live_nghbrs < 2;
}

int shouldLive(Point p, int field[SIZE][SIZE]){
    int live_nghbrs = live_neighbors(p, field);
    return live_nghbrs == 3;
}