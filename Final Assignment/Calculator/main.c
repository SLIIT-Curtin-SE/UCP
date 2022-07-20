#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*Used only in the srand*/
#include <math.h> /*Linked Manually in Makefile*/
#include "terminal.h"
#include "calcpad.h"
#include "functionality.h"
#include "clear.h"
#include "linkedlist.h"
/*Main logic of the program*/
int main(int argc, char* argv[])
{
    int randDisplayOption; /*holds rand option */
    int i;
    char** calculatorPad; /*calculator pad is defined as an array*/
    char* cursor; /*The cursor for the array*/
    int cursorRowLoc = 1;
    int cursorColLoc = 0;
    int total = 0;
    char input;
    char value;
    int exit = 0;
    int calcDisplay = 0;
    LinkedList* undoStack; /*Linkedlist (generic), we call it an undostack because thats how its used*/

    srand(time(0));
    disableBuffer();
    if (argc != 2) /*If no two arguments the program wont execute*/
    {
        printf("Please provide argument correctly: ./calculator <filename>\n");
    }
    else
    {
        initializeLinkedList(&undoStack); /*linkedlist.c we initialize the linkedlist*/
        randDisplayOption = rand() % 2; /*Mod 2 means either randDisplay is 0 or 1*/
        if (randDisplayOption == 0)
        {
            initializeForwardPad(&calculatorPad, &cursor); /*Calcpad is initialized one way*/
        }
        else
        {
            initializeReversePad(&calculatorPad, &cursor); /*or the other, two options are in calcpad.c*/
        }
        while (exit == 0)
        {
            clear();
            displayCurrentValue(calcDisplay); /*The calculator Display*/
            displayCalcPad(calculatorPad); /*The calculator pad*/
            printf("current total: %d\n", total); /*Current total, since its only one line we dont call a function*/
            scanf("%c", &input);
            if (input == 'w' || input == 'a' || input == 's' || input == 'd')
            {
                moveCursor(&calculatorPad, &cursor, &cursorRowLoc, &cursorColLoc, input); /*Function to move the cursor depending on input*/
            }
            if (input == 'e')
            {
                value = getValue(&calculatorPad, &cursorRowLoc, &cursorColLoc); /*We get the corresponding keypad value*/
                if (value == '+') /*If its a +, we add it to the total and insert into linkedlist and reset display*/
                {
                    total = total + calcDisplay;
                    insertFirst(calcDisplay, &undoStack);
                    calcDisplay = 0;
                }
                else if (value == '=') /*if equal we print the linkedlist, total to the file and exit, exit is used as a boolean*/
                {
                    printStack(&undoStack, argv[1], total);
                    exit = 1; /*Could've typeddef it, but a simple 1 for true and 0 for false does the trick*/
                }
                else 
                {
                    if (floor(log10(abs(calcDisplay))) != 6) /*Reason we had to use the math library, this returns the log10 value of the display*/
                    { /*used to prevent the value from exceeding the scrreen size*/
                        calcDisplay = calcDisplay * 10 + value - '0'; /*since value is a char, we use the '0' to convert to int*/
                    }
                }
            }
        } 
        for (i = 0; i < 8; i++)
        {
            free(calculatorPad[i]); /*we free the calculator pad*/
        }
        free(calculatorPad);
    }
    enableBuffer();
    return 0;
}