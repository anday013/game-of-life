#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
void function(short field[SIZE][SIZE], short field2[SIZE][SIZE]){
    for (int r = 0; r < SIZE; r++)
         for (int c = 0; c < SIZE; c++)
                field2[r][c] = field[r][c];
        
}




void print_field(short field[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (field[r][c])
                printf("1 | ");
            else
                printf("0 | ");
        }
        printf("\n");
    }
}
void main(){
    short field[SIZE][SIZE] = {0};
    short newField[SIZE][SIZE] = {0};
    field[1][1] = 1;
    function(field, newField);
    print_field(newField);
}