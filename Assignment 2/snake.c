#include <stdio.h>
#include "snake.h"
/*Program with the snake logic*/
void moveSnake(char*** mapArray, char** snake,  int playerRowLoc, int playerColLoc, int* snakeRowLoc, int* snakeColLoc, int* bit)
{
    char** map = *mapArray;

    if (playerRowLoc > *snakeRowLoc) /*If player is below snake, move down*/
    {
        if (map[*snakeRowLoc + 1][*snakeColLoc] == ' ' || map[*snakeRowLoc + 1][*snakeColLoc] == map[playerRowLoc][playerColLoc])
        {
            map[*snakeRowLoc + 1][*snakeColLoc] = **snake;
            **(snake) = ' ';
            *snake = &map[*snakeRowLoc + 1][*snakeColLoc];
            *snakeRowLoc = *snakeRowLoc + 1;
        }
    }
    else if (playerRowLoc < *snakeRowLoc) /*If player is above snake, move up*/
    {
        if (map[*snakeRowLoc - 1][*snakeColLoc] == ' ' || map[*snakeRowLoc - 1][*snakeColLoc] == map[playerRowLoc][playerColLoc])
        {
            map[*snakeRowLoc - 1][*snakeColLoc] = **snake;
            **(snake) = ' ';
            *snake = &map[*snakeRowLoc - 1][*snakeColLoc];
            *snakeRowLoc = *snakeRowLoc - 1;
        }
    }
    else if (playerColLoc > *snakeColLoc) /*If snake is to the right of the snake, move right*/
    {
        if (map[*snakeRowLoc][*snakeColLoc + 1] == ' ' || map[*snakeRowLoc][*snakeColLoc + 1] == map[playerRowLoc][playerColLoc])
        {
            map[*snakeRowLoc][*snakeColLoc + 1] = **snake;
            **(snake) = ' ';
            *snake = &map[*snakeRowLoc][*snakeColLoc + 1];
            *snakeColLoc = *snakeColLoc + 1;
        }
    }
    else if (playerColLoc < *snakeColLoc) /*If snake it to the left of the snake, move left.*/
    {
        if (map[*snakeRowLoc][*snakeColLoc - 1] == ' ' || map[*snakeRowLoc][*snakeColLoc - 1] == map[playerRowLoc][playerColLoc])
        {
            map[*snakeRowLoc][*snakeColLoc - 1] = **snake;
            **(snake) = ' ';
            *snake = &map[*snakeRowLoc][*snakeColLoc - 1];
            *snakeColLoc = *snakeColLoc - 1;
        }
    }

    if (*snakeColLoc == playerColLoc && *snakeRowLoc == playerRowLoc) /*After moving, if we are at the same place then the snake bites*/
    {
        *bit = 1;
    }
}