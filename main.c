#include "point.h"
#include "game.h"
#include "helper.h"



void main(){
    short field[SIZE][SIZE];
    int stages = 10;
    initialize_field(field);

    change_state(create_point(0,0),field);
    change_state(create_point(1,0),field);
    change_state(create_point(2,0),field);

    
    start_game(stages, field);
}

