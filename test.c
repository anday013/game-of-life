#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define MAX_NEIGHBORS 8

struct Point{
    int row;
    int col;
}typedef Point;


int live_neighbors(Point p, int field[SIZE][SIZE]){
    int live_neighbors = 0;
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
        if(neighbors[i]) live_neighbors++;
    
    return live_neighbors;
}


int shouldDie(Point p, int field[SIZE][SIZE]){
    int live_nghbrs = live_neighbors(p, field);
    if(live_nghbrs == -1) return 0;
    if(live_nghbrs > 3 || live_nghbrs < 2){
        field[p.row][p.col] = 0;
        return 1;
    }
    return 0;
}

void main(){
    int field[SIZE][SIZE];
    for(int r = 0; r < SIZE; r++){
        for(int c = 0; c < SIZE; c++){
            field[r][c] = 0;
        }
    }

    field[1][4] = 1;
    field[3][4] = 1;
    field[2][4] = 1;
    field[2][3] = 1;
    field[3][5] = 1;

    // // clear screen
	// printf("\033[2J");

	// // hide cursor
	// printf("\033[?25l");
    for(int r = 0; r < SIZE; r++){
        for(int c = 0; c < SIZE; c++){
            if(field[r][c])
                printf("1 | ");
            else         
                printf("0 | ");
        }
        printf("\n");
    }
    Point p = {2,4};
    // p.row = 2; 
    // p.col = 4; 
    printf("%d\n",live_neighbors(p,field));

    // printf("\x1b[44m\x1b[31m  \n");
    // printf("\x1b[0m");
    // //show cursor
	// printf("\033[?25h");
}

