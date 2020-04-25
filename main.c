#include "point.h"
#include "game.h"



void main(){
    short field[SIZE][SIZE];
    initialize_field(field);
    Point p0 = create_point(1,4);
    Point p1 = create_point(2,4);
    Point p2 = create_point(3,4);
    Point p3 = create_point(3,5);
    Point p4 = create_point(2,3);

    change_state(p0,field);
    change_state(p1,field);
    change_state(p2,field);
    change_state(p3,field);
    change_state(p4,field);
    
    print_field(field);
 

    printf("%d\n",shouldLive(p0,field));
}

