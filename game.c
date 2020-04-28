#include "game.h"
#include "helper.h"

void change_state(Point p, short field[SIZE][SIZE])
{
    field[p.row][p.col] = !field[p.row][p.col];
}



void start_game(int stages ,short field[SIZE][SIZE]){
    for (int i = 0; i < stages; i++)
    {
        printf("Stage %d: \n\n", i);
        print_field(field);
        printf("-----------------------------------\n");
        next_stage(field);
    }
    
}


void kill(Point p, short field[SIZE][SIZE]){
    field[p.row][p.col] = 0;
}
void born(Point p, short field[SIZE][SIZE]){
        field[p.row][p.col] = 1;
}

void next_stage(short field[SIZE][SIZE]){
    short next_field[SIZE][SIZE];
    copy_field(field, next_field);
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            Point p = create_point(r,c);
            int destiny = live_or_die(p,field);
            if(destiny)
                born(p, next_field);
            else 
                kill(p, next_field);
        }
    }
    copy_field(next_field, field);
}