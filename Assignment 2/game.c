#include <stdlib.h>
#include <stdio.h>
#include "game.h"
/*Function to initialize the map*/
void initializeMap(char*** mapArray, int** metadataArray, int metadataAmount ,int mapRow, int mapCol, char** player, char** snake)
{
    char** map;
    int i;
    int j;
    /*Could've just directly manipulated the array but the precedence not to was set by the map.c functon so I left as is*/
    map = (char**) malloc(sizeof(char*) * mapRow);
    for(i = 0 ; i < (mapRow) ; i++)
    {
        map[i] = (char*) malloc(sizeof(char) * mapCol);
    }
    /*Malloced a 2D array*/
    for (i = 0; i < mapRow; i++)
    {
        for (j = 0; j < mapCol; j++)
        {
            map[i][j] = ' ';
        }
    }
    /*Initializes all elements with an empty space*/
    for (i = 0; i < metadataAmount; i++)
    {
        if(metadataArray[i][2] == 0)
        {
            map[metadataArray[i][0]][metadataArray[i][1]] = '^';
            *player = &map[metadataArray[i][0]][metadataArray[i][1]];
        }
        else if(metadataArray[i][2] == 1)
        {
            map[metadataArray[i][0]][metadataArray[i][1]] = '~';
            *snake = &map[metadataArray[i][0]][metadataArray[i][1]];
        }
        else if(metadataArray[i][2] == 2)
        {
            map[metadataArray[i][0]][metadataArray[i][1]] = 'x';
        }
        else if(metadataArray[i][2] == 3)
        {
            map[metadataArray[i][0]][metadataArray[i][1]] = 'o';
        }
    }
    /*Initializes the map with all the metadata*/
    map[0][0] = '#';
    map[mapRow-1][0] = '#';
    map[0][mapCol-1] = '#';
    map[mapRow-1][mapCol-1] = '#';
    /*Initialized the four corners of the map to be #*/
    for(i=1; i < mapRow-1; i++)
    {
        map[i][0] = '|';
        map[i][mapCol - 1] = '|';
    }

    for(i=1; i < mapCol-1; i++)
    {
        map[0][i] = '-';
        map[mapRow-1][i] = '-';
    }
    /*Initialized the borders of the map to be | and -*/
    *mapArray = map; /*Points mapArray to map*/
}
/*Function to display the map*/
void displayMap(char** mapArray, int mapRow, int mapCol)
{
    int x;
    int y;
    int leftBoundary, rightBoundary, topBoundary, bottomBoundary;
    /*For variables for the four corners that are going to be displayed*/

    leftBoundary = 0;
    rightBoundary = mapCol-1;
    topBoundary = 0;
    bottomBoundary = mapRow-1;

    /*Prints the display according to the defined boundary*/
    for (x = topBoundary; x <= bottomBoundary; x++)
    {
        for (y = leftBoundary; y <= rightBoundary; y++)
        {
            printf("%c", mapArray[x][y]);
        }
        printf("\n");
    }
}

void rotatePlayer(char* player, char input)
{ /*rotates the player character depending on the user input, pass it as a pointer and change the area it is pointing to*/
    if (input == 'w')
    {
        *player = '^';
    }
    else if (input == 'a')
    {
        *player = '<';
    }
    else if (input == 's')
    {
        *player = 'v';
    }
    else if (input == 'd')
    {
        *player = '>';
    }
    /*Alternatively could have passed the array coordinates but this is the most efficient way I could think of.*/
}

void movePlayer(char*** mapArray, char** player , char input, int* playerRowLoc, 
int* playerColLoc, int goalRowLoc, int goalColLoc, int* won)
{

    char** map = *mapArray;
    if (input == 'w')
    {
        if (map[*playerRowLoc - 1][*playerColLoc] == ' ' || map[*playerRowLoc - 1][*playerColLoc] == 'x') /*If empty space or goal character then allow movement*/
        {
            map[*playerRowLoc - 1][*playerColLoc] = **player; /*character of player should be copied to the target location*/
            **(player) = ' '; /*Location the character was in should be turned into a ' ' space, since player isnt there anymore */
            *player = &map[*playerRowLoc - 1][*playerColLoc]; /*pointer of player should now point to the target location since the player has moved there*/
            *playerRowLoc = *playerRowLoc -1; /*The x and y index of the player should be updated appropriately*/
        }
    }
    else if (input == 'a')
    { /*in all cases of w a s d we do the same set of instructions, only difference is that the target location changes*/
        if (map[*playerRowLoc][*playerColLoc - 1] == ' ' || map[*playerRowLoc][*playerColLoc - 1] == 'x') /*If empty space or goal character then allow movement*/
        {
            map[*playerRowLoc][*playerColLoc - 1] = **player;
            **(player) = ' ';
            *player = &map[*playerRowLoc][*playerColLoc - 1];
            *playerColLoc = *playerColLoc - 1;
        }
    }
    else if (input == 's')
    {
       if (map[*playerRowLoc + 1][*playerColLoc] == ' ' || map[*playerRowLoc + 1][*playerColLoc] == 'x') /*If empty space or goal character then allow movement*/
        {
            map[*playerRowLoc + 1][*playerColLoc] = **player;
            **(player) = ' ';
            *player = &map[*playerRowLoc + 1][*playerColLoc];
            *playerRowLoc = *playerRowLoc + 1;
        }
    }
    else if (input == 'd')
    {
       if (map[*playerRowLoc][*playerColLoc + 1] == ' ' || map[*playerRowLoc][*playerColLoc + 1] == 'x') /*If empty space or goal character then allow movement*/
        {
            map[*playerRowLoc][*playerColLoc + 1] = **player;
            **(player) = ' ';
            *player = &map[*playerRowLoc][*playerColLoc + 1];
            *playerColLoc = *playerColLoc + 1;
        } 
    }

    if (*playerRowLoc == goalRowLoc && *playerColLoc == goalColLoc)
    {
        *won = 1;
    } /*If the player x and y coordinates match with the goal x and y coordinates we have won!, change this to one so we can break the loop*/


}
