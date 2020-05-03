#include "circular.h"

int circular_live_neighbors(Point p, short field[SIZE][SIZE]){
    int neighbors[MAX_NEIGHBORS] = {0};
    int alive = 0;
    if(p.row == 0 && p.col != 0 && p.col != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row + 1][p.col + 1];
        neighbors[2] = field[p.row + 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];       
        neighbors[5] = field[LIMIT][p.col - 1];       
        neighbors[6] = field[LIMIT][p.col];       
        neighbors[7] = field[LIMIT][p.col + 1];       
    } 
    else if(p.row == LIMIT && p.col != 0 && p.col != LIMIT){
        neighbors[0] = field[p.row - 1][p.col];
        neighbors[1] = field[p.row - 1][p.col + 1];
        neighbors[2] = field[p.row - 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];
        neighbors[5] = field[0][p.col - 1];       
        neighbors[6] = field[0][p.col];       
        neighbors[7] = field[0][p.col + 1];    
    }
    else if(p.col == 0 && p.row != 0 && p.row != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row + 1][p.col + 1];
        neighbors[3] = field[p.row - 1][p.col + 1];
        neighbors[4] = field[p.row][p.col + 1];  
        neighbors[5] = field[p.row][LIMIT];       
        neighbors[6] = field[p.row + 1][LIMIT];       
        neighbors[7] = field[p.row - 1][LIMIT];  
    }
    else if(p.col == LIMIT && p.row != 0 && p.row != LIMIT){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row + 1][p.col - 1];
        neighbors[3] = field[p.row - 1][p.col - 1];
        neighbors[4] = field[p.row][p.col - 1];  
        neighbors[5] = field[p.row][0];       
        neighbors[6] = field[p.row + 1][0];       
        neighbors[7] = field[p.row - 1][0];  
    }
    else if(p.col == 0 && p.row == 0){
        neighbors[0] = field[0][1];
        neighbors[1] = field[1][0];
        neighbors[2] = field[1][1];

        neighbors[3] = field[1][LIMIT];
        neighbors[4] = field[LIMIT][1];
        neighbors[5] = field[LIMIT][LIMIT];       
        neighbors[6] = field[LIMIT][0];       
        neighbors[7] = field[0][LIMIT]  ;  
    }
    else if(p.col == LIMIT && p.row == 0){
        neighbors[0] = field[1][LIMIT];
        neighbors[1] = field[0][LIMIT - 1];
        neighbors[2] = field[1][LIMIT - 1];

        neighbors[3] = field[0][0];
        neighbors[4] = field[LIMIT][LIMIT - 1];
        neighbors[5] = field[LIMIT][LIMIT];       
        neighbors[6] = field[LIMIT][0];       
        neighbors[7] = field[1][0];  
    }
    else if(p.col == 0 && p.row == LIMIT){
        neighbors[0] = field[LIMIT - 1][p.col];
        neighbors[1] = field[LIMIT][1];
        neighbors[2] = field[LIMIT - 1][1];

        neighbors[3] = field[0][0];
        neighbors[5] = field[LIMIT][LIMIT]; 
        neighbors[4] = field[0][1];
        neighbors[6] = field[LIMIT - 1][LIMIT];       
        neighbors[7] = field[0][LIMIT]  ;  
    }
    else if(p.col == LIMIT && p.row == LIMIT){
        neighbors[0] = field[p.row][p.col - 1];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row - 1][p.col - 1];
        neighbors[3] = field[0][0];
        neighbors[4] = field[0][LIMIT - 1];
        neighbors[5] = field[LIMIT][0]; 
        neighbors[6] = field[LIMIT - 1][0];       
        neighbors[7] = field[0][LIMIT]  ;  
    }
    for(int i = 0; i < MAX_NEIGHBORS; i++)
        if(neighbors[i]) alive++;
    return alive;
}