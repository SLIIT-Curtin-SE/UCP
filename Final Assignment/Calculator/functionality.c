#include "functionality.h"
#include <stdio.h>
/*Where the user functionality is recorded*/
void displayCalcPad(char** calcpad) /*Displays the calcpad, whichever way it is initialized*/
{
    int i;
    int j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", calcpad[i][j]);
        }
        printf("\n");
    }
}

void displayCurrentValue(int total) /*Display the calcPad display*/
{
    int i;
    for (i = 0; i < 9; i++)
    {
        printf("_");
    }
    printf("\n");
    printf("|");
    printf("%7d", total);
    printf("|\n");
    for (i = 0; i < 9; i++)
    {
        printf("_");
    }
    printf("\n");
}

void moveCursor(char*** calcpad, char** cursor, int* cursorRowLoc, int* cursorColLoc, char input) /*Ability to move the cursor using
wasd*/
{
    char** pad = *calcpad;
    if (input == 'w')
    {
        if(*cursorRowLoc != 1)
        {
            pad[*cursorRowLoc - 2][*cursorColLoc] = **cursor;
            **(cursor) = ' ';
            *cursor = &pad[*cursorRowLoc - 2][*cursorColLoc];
            *cursorRowLoc = *cursorRowLoc - 2;
        }
    }
    else if (input == 'a')
    {
        if (*cursorColLoc != 0)
        {
            pad[*cursorRowLoc][*cursorColLoc -1] = **cursor;
            **(cursor) = ' ';
            *cursor = &pad[*cursorRowLoc][*cursorColLoc -1];
            *cursorColLoc = *cursorColLoc - 1;
        }
    }
    else if (input == 's')
    {
        if (*cursorRowLoc != 7)
        {
            pad[*cursorRowLoc + 2][*cursorColLoc] = **cursor;
            **(cursor) = ' ';
            *cursor = &pad[*cursorRowLoc + 2][*cursorColLoc];
            *cursorRowLoc = *cursorRowLoc + 2;
        }
    }
    else if (input == 'd')
    {
        if (*cursorColLoc != 2)
        {
            pad[*cursorRowLoc][*cursorColLoc +1] = **cursor;
            **(cursor) = ' ';
            *cursor = &pad[*cursorRowLoc][*cursorColLoc +1];
            *cursorColLoc = *cursorColLoc + 1;
        }
    }
}

char getValue(char*** calcpad, int* cursorRowLoc, int* cursorColLoc) /*When the e button is pressed it will get the relevant char
to whatever the cursor is pointing to*/
{
    char** pad = *calcpad;
    char returnValue = pad[*cursorRowLoc -1][*cursorColLoc];
    return returnValue;
}