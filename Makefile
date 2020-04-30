CC = gcc

all: game.c helper.c point.c main.c


clean: 
		rm -f *.o sieve

game: game.c helper.c point.c main.c
	$(CC) $^ -o game