#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "map.h"
#include "terminal.h"
#include "clear.h"

/*This is the main function that will be run when you start the code upon compilation*/
int main(int argc, char* argv[])
{
    
    int** metadataArray; 
    char** mapArray; /*This is the 2d represenation of the map, not to be confused with the array with metadata FOR the map */
    int metadataAmount, mapRow, mapCol; /*These values will be passed as ref so they can be loaded with values by the map.c file*/
    int x;
    char input;
    int visibility = 0; /*We initialize visibility to 0, mainly because C doesnt like us keeping this uninitialized*/
    char* player = NULL;
    int playerRowLoc, playerColLoc; /*X and Y cordinates of the player */
    int goalRowLoc, goalColLoc; /*X and Y coordinated of the goal */
    int won = 0; /*Could've typedef a boolean, but this is only used to break the loop, if 0 game continues, if 1 game is won */

    disableBuffer(); /*We disable the buffer, using the function from terminal.c*/
    if (argc != 2 || *argv[1] == '-') /*If we aren't passing 2 arguments (name of exec and visibility) program prints error code and ends.*/
    { /*If the first character of a integer is - then its negative, program ends*/
        printf("Just enter one parameter for visibilty and no negative values!\n");
    }
    else
    {   
        #ifndef DARK /*If DARK was not defined upon compilation then visibility becomes 0*/
            visibility = 0;
        #else
            visibility = atoi(argv[1]); /*If dark was defined, then we assign the value visibility to the string that was passed*/
        #endif  /*atoi is a function that converts a string to int in the java util library*/

        getMetadata(&metadataArray, &metadataAmount, &mapRow, &mapCol); /*Intialize our metadataArray from the map.c function*/
        initializeMap(&mapArray, metadataArray ,metadataAmount, mapRow, mapCol, &player); /*initialized our 2d array representation*/
        /*We get back the memory location of the player as well*/
        playerRowLoc = metadataArray[0][0];
        playerColLoc = metadataArray[0][1];
        goalRowLoc = metadataArray[1][0];
        goalColLoc = metadataArray[1][1];
        /*Assign the x and y coordinates of both the goal and the player!*/
        clear(); /*we clear the terminal*/
        displayMap(mapArray, mapRow, mapCol, visibility, &playerRowLoc, &playerColLoc);
        /*We display this once and then display clear again inside the loop because the final move is not displayed*/
        while (won == 0) /*makeshift boolean, if won == 0 then havent won, if won == 1 then have won!*/
        {
            scanf("%c", &input); /*Get the users input, w, a, s, d*/
            rotatePlayer(player, input); /*First we rotate the player, game.c function*/
            movePlayer(&mapArray, &player , input, mapCol, mapRow, &playerRowLoc, &playerColLoc, goalRowLoc, goalColLoc, &won); 
            clear(); /*Move the player clear the screen and display the map*/
            displayMap(mapArray, mapRow, mapCol, visibility, &playerRowLoc, &playerColLoc);
        }
        /*If we exit the loop that means we won, so print this*/
        printf("Wohoo found it!\n");
        
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
        /*Free both the 2d arrays and the pointers to them, to prevent memory leaks*/
    }

    enableBuffer(); /*Enable the buffer again*/
    return 0; /*Exit program*/
}


