#include "point.h"
#include "game.h"
#include "helper.h"



void main(int args, char **argv){
    short field[SIZE][SIZE];
    if(args != 2){
        perror("Wrong arguments. Please check documentation");
        exit(0);
    }
    if(argv[1] != "1" || argv[1] != "2"){
        perror("Version can be 1 or 2");
        exit(0);
    }
    int version = atoi(argv[1]);
    int stages = 10;
    initialize_field(field);

    change_state(create_point(0,0),field);
    change_state(create_point(1,0),field);
    change_state(create_point(2,0),field);

    
    start_game(stages, field, version);
}

