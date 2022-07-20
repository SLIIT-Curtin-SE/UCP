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

#Add DARK flag to the CFLAGS and recompile

ifdef DARK
DFLAG = -D DARK
DARK : clean $(EXEC)
endif

$(EXEC) : main.o map.o game.o terminal.o clear.o
	$(CC) main.o map.o game.o terminal.o clear.o -o $(EXEC)

main.o : main.c map.h
	$(CC) -c main.c $(CFLAGS) $(DFLAG)

map.o : map.c map.h
	$(CC) -c map.c $(CFLAGS)

game.o : game.c game.h
	$(CC) -c game.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

clear.o : clear.c clear.h
	$(CC) -c clear.c $(CFLAGS)

clean:
	rm -f $(EXEC) main.o map.o game.o terminal.o clear.o