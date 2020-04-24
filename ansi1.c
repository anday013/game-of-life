#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	const int N = 20;
	// clear screen
	printf("\033[2J");

	// hide cursor
	printf("\033[?25l");

	// goto 0,0
	for(int i= 0; i<N; ++i)
	{
		printf("\033[%d;4H",i+2);
		for(int j= 0; j<N; ++j)
		{
			int c = (i%2 == j%2) ? 40 : 104;
			printf("\033[%dm  ",c);
			// draw 2 space with color 40 or 101 (black or magenta)
		}
//		printf("\n");
	}

	//show cursor
	printf("\033[?25h");
	return 0;
}
