#include "helper.h"

int copy_field(short src_field[SIZE][SIZE], short new_field[SIZE][SIZE]){
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            new_field[r][c] = src_field[r][c];
}


void initialize_field(short field[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            field[r][c] = 0;
}

// void print_field(short field[SIZE][SIZE])
// {
//     for (int r = 0; r < SIZE; r++)
//     {
//         for (int c = 0; c < SIZE; c++)
//         {
//             if (field[r][c])
//                 printf("1 | ");
//             else
//                 printf("0 | ");
//         }
//         printf("\n");
//     }
// }
