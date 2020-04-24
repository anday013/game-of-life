#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define MAX_NEIGHBORS 8

struct Point{
    int row;
    int col;
}typedef Point;




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

    // printf("\x1b[44m\x1b[31m  \n");
    // printf("\x1b[0m");
    // //show cursor
	// printf("\033[?25h");
}

