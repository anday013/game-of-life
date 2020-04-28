#include "point.h"

int check_point(Point p, int rows, int cols){
    if(p.col < cols && p.row < rows)
        return 1;
    perror("Point ( %d, %d ) does not belong to game board");
    return 0;
}

Point create_point(int row, int col){
    Point p = {row, col};
    if(check_point(p, SIZE, SIZE))
        return p;
    perror("Point creation failed...");
    exit(0); 
}

int alive_or_dead(Point p, short field[SIZE][SIZE]){
    return field[p.row][p.col];
}
/////////////////////////////////////////////////////////
int clipped_live_neighbors(Point p, short field[SIZE][SIZE]){
    int max_neighbors = MAX_NEIGHBORS - 3; // 5
    int neighbors[5] = {0};
    int limit = SIZE - 1;
    int alive = 0;
    if(p.row == 0 && p.col != 0 && p.col != limit){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row + 1][p.col + 1];
        neighbors[2] = field[p.row + 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];       
    } 
    else if(p.row == limit && p.col != 0 && p.col != limit){
        neighbors[0] = field[p.row - 1][p.col];
        neighbors[1] = field[p.row - 1][p.col + 1];
        neighbors[2] = field[p.row - 1][p.col - 1];
        neighbors[3] = field[p.row][p.col + 1];
        neighbors[4] = field[p.row][p.col - 1];  
    }
    else if(p.col == 0 && p.row != 0 && p.row != limit){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row + 1][p.col + 1];
        neighbors[3] = field[p.row - 1][p.col + 1];
        neighbors[4] = field[p.row][p.col + 1];  
    }
    else if(p.col == limit && p.row != 0 && p.row != limit){
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
    else if(p.col == limit && p.row == 0){
        neighbors[0] = field[p.row + 1][p.col];
        neighbors[1] = field[p.row][p.col - 1];
        neighbors[2] = field[p.row + 1][p.col - 1];
    }
    else if(p.col == 0 && p.row == limit){
        neighbors[0] = field[p.row - 1][p.col];
        neighbors[1] = field[p.row][p.col + 1];
        neighbors[2] = field[p.row - 1][p.col + 1];
    }
    else if(p.col == limit && p.row == limit){
        neighbors[0] = field[p.row][p.col - 1];
        neighbors[1] = field[p.row - 1][p.col];
        neighbors[2] = field[p.row - 1][p.col - 1];
    }
    for(int i = 0; i < max_neighbors; i++)
        if(neighbors[i]) alive++;
    return alive;
}

////////////////////////////////////////////////

int is_critical(Point p){
    return p.row == LIMIT || p.row == 0 || p.col == LIMIT || p.col == 0;
}

int live_neighbors(Point p, short field[SIZE][SIZE]){
    int alive = 0;
    if(is_critical)
        alive = clipped_live_neighbors(p,field);
    else{
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
    }
    
    return alive;
}

int shouldDie(Point p, short field[SIZE][SIZE]){
    if(!alive_or_dead(p,field)) return 1;
    int live_nghbrs = live_neighbors(p, field);
    return live_nghbrs > 3 || live_nghbrs < 2;
}

int shouldLive(Point p, short field[SIZE][SIZE]){
    if(alive_or_dead(p,field)) return 0;
    return live_neighbors(p, field) == 3;
}



