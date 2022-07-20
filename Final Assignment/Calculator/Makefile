##
 # File: Makefile
 # Author: Sahas Gunasekara
 # -----
 # Modified By: Sahas Gunasekara
 # -----
 # Purpose: Makefile for final assignment
##

# Makefile Variables
CC = gcc
EXEC = calculator
CFLAGS = -Wall -ansi -pedantic -Werror

$(EXEC) : main.o terminal.o calcpad.o functionality.o clear.o linkedlist.o
	$(CC) main.o terminal.o calcpad.o functionality.o clear.o linkedlist.o -o $(EXEC) -lm

main.o : main.c
	$(CC) -c main.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

calcpad.o : calcpad.c calcpad.h
	$(CC) -c calcpad.c $(CFLAGS)

functionality.o : functionality.c functionality.h
	$(CC) -c functionality.c $(CFLAGS)

clear.o : clear.c clear.h
	$(CC) -c clear.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)

clean:
	rm -f $(EXEC) main.o terminal.o calcpad.o functionality.o clear.o linkedlist.o