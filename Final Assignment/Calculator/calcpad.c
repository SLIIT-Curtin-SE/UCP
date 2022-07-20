#include "calcpad.h"
#include <stdlib.h>
/*Initialized one of two of these formats for the calculator pad*/
void initializeForwardPad(char*** calculatorPad, char** cursor)
{
    char** pad;
    int i;

    pad = (char**) malloc(sizeof(char*) * 8);
    for (i = 0; i < 8; i++)
    {
        pad[i] = (char*) malloc(sizeof(char) * 3);
    }
    pad[0][0] = '+';
    pad[0][1] = '0';
    pad[0][2] = '=';
    pad[2][0] = '7';
    pad[2][1] = '8';
    pad[2][2] = '9';
    pad[4][0] = '4';
    pad[4][1] = '5';
    pad[4][2] = '6';
    pad[6][0] = '1';
    pad[6][1] = '2';
    pad[6][2] = '3';

    for (i= 1; i < 8; i+=2) /*Cursor always pointing to the first element in first row/first col*/ 
    {
        pad[i][0] = ' ';
        pad[i][1] = ' ';
        pad[i][2] = ' ';
    }
    pad[1][0] = '^';
    *cursor = &pad[1][0]; /*Cursor always pointing to the first element in first row/first col*/
    *calculatorPad = pad;
}

void initializeReversePad(char*** calculatorPad, char** cursor)
{
    char** pad;
    int i;

    pad = (char**) malloc(sizeof(char*) * 8);
    for (i = 0; i < 8; i++)
    {
        pad[i] = (char*) malloc(sizeof(char) * 3);
    }
    pad[0][0] = '1';
    pad[0][1] = '2';
    pad[0][2] = '3';
    pad[2][0] = '4';
    pad[2][1] = '5';
    pad[2][2] = '6';
    pad[4][0] = '7';
    pad[4][1] = '8';
    pad[4][2] = '9';
    pad[6][0] = '+';
    pad[6][1] = '0';
    pad[6][2] = '=';

    for (i= 1; i < 8; i+=2) /*Cursor always pointing to the first element in first row/first col*/
    {
        pad[i][0] = ' ';
        pad[i][1] = ' ';
        pad[i][2] = ' ';
    }
    pad[1][0] = '^';
    *cursor = &pad[1][0]; /*Cursor always pointing to the first element in first row/first col*/
    *calculatorPad = pad;
}