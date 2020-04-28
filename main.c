#include "point.h"
#include "game.h"
#include "helper.h"



void main(){
    short field[SIZE][SIZE];
    int stages = 50;
    initialize_field(field);
    Point p0 = create_point(4,4);
    Point p1 = create_point(5,4);
    Point p2 = create_point(6,4);
    // Point p3 = create_point(3,5);
    // Point p4 = create_point(2,3);

    change_state(p0,field);
    change_state(p1,field);
    change_state(p2,field);
    // change_state(p3,field);
    // change_state(p4,field);
    
    short new_field[SIZE][SIZE];

    // copy_field(field, new_fiel/d);
    // print_field(new_field);
    // printf("%d\n", live_neighbors(p1, field));
    // printf("%d\n", shouldLive(p0, field));
    // printf("%d\n", shouldLive(p1, field));
    // printf("%d\n", shouldLive(p2, field));
    // printf("%d\n", shouldLive(p3, field));
    // printf("%d\n", shouldLive(p4, field));
    
    start_game(stages, field);
}

