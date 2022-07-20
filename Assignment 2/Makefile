##
 # File: Makefile
 # Author: Sahas Gunasekara
 # -----
 # Modified By: Sahas Gunasekara
 # -----
 # Purpose: Makefile for assignment
##

# Makefile Variables
CC = gcc
EXEC = maze
CFLAGS = -Wall -ansi -pedantic -Werror

$(EXEC) : main.o map.o game.o terminal.o clear.o snake.o linkedlist.o
	$(CC) main.o map.o game.o terminal.o clear.o snake.o linkedlist.o -o $(EXEC)

main.o : main.c map.h
	$(CC) -c main.c $(CFLAGS)

map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)

game.o : game.c game.h
	$(CC) -c game.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clear.o : clear.c clear.h
	$(CC) -c clear.c $(CFLAGS)

snake.o : snake.c snake.h
	$(CC) -c snake.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)

clean:
	rm -f $(EXEC) main.o map.o game.o terminal.o clear.o linkedlist.o snake.o