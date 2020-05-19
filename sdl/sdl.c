#include "sdl.h"


void draw(SDL_Renderer *renderer, short field[_size][_size])
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color to black
	SDL_RenderClear(renderer); // Paint window to black

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set color to white
	for (int row = 0; row < _size; ++row)
	{
		for (int col = 0; col < _size; ++col)
		{

			if (field[row][col])
			{
				SDL_Rect rectangle; // Draw rectangle (live cell)
				rectangle.h = SCALE;
				rectangle.w = SCALE;
				rectangle.y = SCALE * row;
				rectangle.x = SCALE * col;
				SDL_RenderFillRect(renderer, &rectangle);
			}
		}
	}
}


void mouse_listener(SDL_Renderer *renderer, short field[_size][_size], bool isActive)
{
	int x, y;
	if ((SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT) && isActive))
	{
		// USE COLOR
		int col, row;
		col = x / ((int)SCALE);
		row = y / ((int)SCALE);
		field[row][col] = 1;
		draw(renderer, field);
		SDL_RenderPresent(renderer);
	}
}


int get_size(char *object){
	int decleared_number_size = 4;
    char *size = malloc(sizeof(char) * decleared_number_size);
    printf("\n%s size: \n", object);
     if(scanf("%s", size))
        getchar();
    else
        FAIL_IF_MSG(1,"Failed to read integer");
    FAIL_IF_MSG(strlen(size) > decleared_number_size, "Quite big number");
    for (int i = 0; i < strlen(size); i++)
    {
        FAIL_IF_MSG(size[i] < '0' && size[i] > '9', "Invalid window size value");
    }
    return atoi(size);
}


void window_reset(SDL_Renderer *renderer, short field[_size][_size]){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	initialize_field(field);
}


void game_run(SDL_Renderer *renderer, short field[_size][_size], int version){
	draw(renderer, field);
	SDL_RenderPresent(renderer);
	usleep(500000);
	next_stage(field, version);
}


void sdl_run(int version)
{
	_size = get_size("Field (Number of cells in a row)"); // Array size
	_window_size = get_size("Window (px)");
	FAIL_IF_MSG(_size > _window_size, "Error: Field (Table) size is bigger than Window size");
	printf("\nENTER - start game\nSPACE - pause game\nESC - restart game\n");
	short field[_size][_size];
	initialize_field(field);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Problem can not init SDL2 \n");
		return;
	}

	// Creating window
	SDL_Window *window = SDL_CreateWindow("Game of Life",
										  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										  _window_size, _window_size, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert(renderer != NULL);

	// Make window black 
	window_reset(renderer, field);

	// Game required flags
	bool quit = false;
	bool start_game = false;
	bool pause_game = false;
	bool mouse_isActive = true;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_RETURN: // 'Enter' press case: game starts
					start_game = true;
					mouse_isActive = false;
					break;
				case SDLK_SPACE: // 'Space' press case: game pauses
					if(start_game)
						pause_game = !pause_game;
					break;
				case SDLK_ESCAPE: // 'Escape' press case: game ends and waits for new
					start_game = !start_game;
					mouse_isActive = true;
					pause_game = false;
					window_reset(renderer, field);
					break;
				}
				break;
			}
		}

		mouse_listener(renderer, field, mouse_isActive); // Listening for mouse events

		if (start_game && !pause_game)
		{
			game_run(renderer, field, version);
		}
	}
	SDL_Quit();
}
