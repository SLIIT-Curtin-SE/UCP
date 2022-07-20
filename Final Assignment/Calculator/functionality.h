#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

void displayCalcPad(char** calcpad);

void displayCurrentValue(int total);

void moveCursor(char*** calcpad, char** cursor, int* cursorRowLoc, int* cursorColLoc, char input);

char getValue(char*** calcpad, int* cursorRowLoc, int* cursorColLoc);

#endif