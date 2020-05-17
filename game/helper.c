#include "helper.h"

int get_version()
{
    printf("Version: (circular - 0, clipped - 1)\n");
    char version = '0';
    if(scanf("%c", &version))
        getchar();
    else
        FAIL_IF_MSG(1,"Failed to read integer");
    
    FAIL_IF_MSG(version < '0' || version > '1', "Wrong version input");
    return version - '0';
}


int get_game_type(){
    printf("\nConsole or SDL: (console - 0, SDL - 1)\n");
    char game_type = '0';
    if(scanf("%c", &game_type))
        getchar();
    else
        FAIL_IF_MSG(1,"Failed to read integer");
    FAIL_IF_MSG(game_type < '0' || game_type > '1', "Wrong game type");
    return game_type - '0';
}

int get_stages()
{
    int decleared_number_size = 10;
    char *stages = malloc(sizeof(char) * decleared_number_size);
    printf("\nNumber of stages: \n");
     if(scanf("%s", stages))
        getchar();
    else
        FAIL_IF_MSG(1,"Failed to read integer");
    FAIL_IF_MSG(strlen(stages) > decleared_number_size, "Quite big number");
    for (int i = 0; i < strlen(stages); i++)
    {
        FAIL_IF_MSG(stages[i] < '0' && stages[i] > '9', "Invalid stages value");
    }
    return atoi(stages);

}

int copy_field(short src_field[_size][_size], short new_field[_size][_size])
{
    for (int r = 0; r < _size; r++)
        for (int c = 0; c < _size; c++)
            new_field[r][c] = src_field[r][c];
    return 1;
}

int initialize_field(short field[_size][_size])
{
    for (int r = 0; r < _size; r++)
        for (int c = 0; c < _size; c++)
            field[r][c] = 0;
    return 1;
}

int locate_points(Point points[], int length, short field[_size][_size])
{
    for (int i = 0; i < length; i++)
        change_state(points[i], field);
    return 1;
}