#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "terminal.h"
#include "clear.h"
#include "snake.h"
#include "linkedlist.h"

/*This is the main function that will be run when you start the code upon compilation*/
int main(int argc, char* argv[])
{
    int** metadataArray; 
    char** mapArray; /*This is the 2d represenation of the map, not to be confused with the array with metadata FOR the map */
    int metadataAmount, mapRow, mapCol; /*These values will be passed as ref so they can be loaded with values by the map.c file*/
    int x;
    char input;
    char* player = NULL;
    char* snake = NULL;
    int playerRowLoc, playerColLoc; /*X and Y cordinates of the player */
    int goalRowLoc, goalColLoc; /*X and Y coordinated of the goal */
    int snakeRowLoc, snakeColLoc; /*X and Y coordinated of the snake */
    int won = 0; /*Could've typedef a boolean, but this is only used to break the loop, if 0 game continues, if 1 game is won */
    int bit = 0;
    LinkedList* undoStack;

    disableBuffer(); /*We disable the buffer, using the function from terminal.c*/
    if (argc != 2) /*If we aren't passing 2 arguments (name of exec and visibility) program prints error code and ends.*/
    { /*If the first character of a integer is - then its negative, program ends*/
        printf("Just enter one parameter for file name!\n");
    }
    else
    {
        int status = fileExists(argv[1]); /*Status is a boolean alternative, if status is one that means the file exists!*/
        if (status == 1)
        {
            initializeLinkedList(&undoStack); /*We initialize the undo stack*/

            getMetadata(&metadataArray, &metadataAmount, &mapRow, &mapCol, argv[1]); /*We recieve a metadata array with all the details*/
            initializeMap(&mapArray, metadataArray , metadataAmount, mapRow, mapCol, &player, &snake); /*initialized our 2d array representation*/
            /*We get back the memory location of the player as well*/
            playerRowLoc = metadataArray[0][0];
            playerColLoc = metadataArray[0][1];
            goalRowLoc = metadataArray[1][0];
            goalColLoc = metadataArray[1][1];
            snakeRowLoc = metadataArray[2][0];
            snakeColLoc = metadataArray[2][1];
            /*Assign the x and y coordinates of both the goal and the player!*/
            clear(); /*we clear the terminal*/
            displayMap(mapArray, mapRow, mapCol);
            /*We display this once and then display clear again inside the loop because the final move is not displayed*/
            while (won == 0 && bit == 0) /*makeshift boolean, if won == 0 then havent won, if won == 1 then have won!*/
            {
                scanf("%c", &input); /*Get the users input, w, a, s, d*/
                if (input == 'u') /*If user clicks on u then we undo the move*/
                {
                    clear();
                    getFirst(&player, &playerRowLoc, &playerColLoc, &snake, &snakeRowLoc, &snakeColLoc ,&undoStack); /*We get the users last
                    orientation and location, snakes location as well*/
                    movePlayer(&mapArray, &player, input, &playerRowLoc, &playerColLoc, goalRowLoc, goalColLoc, &won);
                    /*move the player according to the data, snake is automatically moved*/
                    displayMap(mapArray, mapRow, mapCol);
                }
                else if (input == 'w' || input == 'a' || input == 's' || input == 'd')
                {
                    clear(); /*Move the player clear the screen and display the map*/
                    insertFirst(&player, &playerRowLoc, &playerColLoc, &snake, &snakeRowLoc, &snakeColLoc , &undoStack);
                    rotatePlayer(player, input); /*First we rotate the player, game.c function*/
                    movePlayer(&mapArray, &player , input, &playerRowLoc, &playerColLoc, goalRowLoc, goalColLoc, &won); 
                    moveSnake(&mapArray, &snake, playerRowLoc, playerColLoc, &snakeRowLoc, &snakeColLoc, &bit);   
                    displayMap(mapArray, mapRow, mapCol);
                }
            }
            /*If we exit the loop that means we won or we got bit, so print either*/
            
            if (won == 1)
            {
                printf("You won the game!\n");
            }
            else
            {
                printf("Oh no!, the Snake got to you!\n");
            }

            for (x = 0; x < metadataAmount; x++)
            {
                free(metadataArray[x]);
            }
            free(metadataArray);
            
            for (x = 0; x < mapRow; x++)
            {
                free(mapArray[x]);
            }
            free(mapArray);

            freeUndoStack(undoStack);
            /*Free both the 2d arrays and the pointers to them, to prevent memory leaks, also the Linked List is freed*/
        }
        else
        {
            printf("Program shutting down\n");
            /*If something goes wrong just print this and end gracefully*/
        }
    }
    

    enableBuffer(); /*Enable the buffer again*/
    return 0; /*Exit program*/
}


