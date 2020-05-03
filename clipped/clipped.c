#include "clipped.h"
int clipped_live_neighbors(Point p, short field[SIZE][SIZE]){
    int neighbors[CLIPPED_NEIGHBORS] = {0};
    int alive = 0;
    if(p.row == 0 && p.col != 0 && p.col != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row + 1][p.col + 1];
        neighbors[2] = field[p.row + 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];       
    } 
    else if(p.row == LIMIT && p.col != 0 && p.col != LIMIT){
        neighbors[0] = field[p.row - 1][p.col];
        neighbors[1] = field[p.row - 1][p.col + 1];
        neighbors[2] = field[p.row - 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];  
    }
    else if(p.col == 0 && p.row != 0 && p.row != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row + 1][p.col + 1];
        neighbors[3] = field[p.row - 1][p.col + 1];
        neighbors[4] = field[p.row][p.col + 1];  
    }
    else if(p.col == LIMIT && p.row != 0 && p.row != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row + 1][p.col - 1];
        neighbors[3] = field[p.row - 1][p.col - 1];
        neighbors[4] = field[p.row][p.col - 1];  
    }
    else if(p.col == 0 && p.row == 0){
        neighbors[0] = field[p.row][p.col + 1];
        neighbors[1] = field[p.row + 1][p.col];
        neighbors[2] = field[p.row + 1][p.col + 1];
    }
    else if(p.col == LIMIT && p.row == 0){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row][p.col - 1];
        neighbors[2] = field[p.row + 1][p.col - 1];
    }
    else if(p.col == 0 && p.row == LIMIT){
        neighbors[0] = field[p.row - 1][p.col];
        neighbors[1] = field[p.row][p.col + 1];
        neighbors[2] = field[p.row - 1][p.col + 1];
    }
    else if(p.col == LIMIT && p.row == LIMIT){
        neighbors[0] = field[p.row][p.col - 1];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row - 1][p.col - 1];
    }
    for(int i = 0; i < CLIPPED_NEIGHBORS; i++)
        if(neighbors[i]) alive++;
    return alive;
}