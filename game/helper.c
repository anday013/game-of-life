#include "helper.h"


void argument_checker(int args, char **argv){
    FAIL_IF_MSG(args < 2,"Wrong arguments. Please check documentation");
    if(args == 3)
    {
        char *s_stages = argv[2];
        for(int i = 0; i < strlen(s_stages); i++){
            FAIL_IF_MSG(s_stages[i] < '0' && s_stages[i] > '9', "Invalid stages value");
        }
    }
    char *s_version = argv[1];
    FAIL_IF_MSG((strcmp(s_version, "1") && strcmp(s_version, "2")),"Version can be 1 or 2");
}

int get_version(int args, char **argv){
    argument_checker(args, argv);
    return atoi(argv[1]);

}

int get_stages(int args, char **argv){
    argument_checker(args, argv);
    if(args == 3)
        return atoi(argv[2]);
    return 0;
}

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

void locate_points(Point points[], int size, short field[SIZE][SIZE]){
    for(int i = 0; i < size; i++)
        change_state(points[i], field);
}