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

//Complete
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
        neighbors[0] = field[p.row][p.col + 1];
        neighbors[1] = field[p.row + 1][p.col];
        neighbors[2] = field[p.row + 1][p.col + 1];

        neighbors[3] = field[p.row + 1][p.col + 1];
        neighbors[4] = field[p.row + 1][p.col + 1];
        neighbors[5] = field[LIMIT][LIMIT];       
        neighbors[6] = field[LIMIT + 1][LIMIT];       
        neighbors[7] = field[LIMIT][LIMIT - 1];  
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
    if(is_critical(p))
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






int live_or_die(Point p, short field[SIZE][SIZE]){
    int live_nghbrs = live_neighbors(p, field);
    if(field[p.row][p.col])
        return live_nghbrs == 3 || live_nghbrs == 2;  
    else
        return live_nghbrs == 3;
}