#include <stdlib.h>
#include <stdio.h>
#include"map.h"

/*  This file reads a text file that was entered into the argument line and generates a map*/

void getMetadata(int *** metadataTable, int * metadataAmount, int * mapRow, int * mapCol, char* fileName)
{
    int x, y, z;
    int ** table;
    int count = 2;
    int i;

    FILE* f = fopen(fileName, "r"); /*Open file by the name, we already know it exists because we checked in the fileExists()*/
    
    fscanf(f, "%d %d %d", &x, &y, &z); /*We know how it is ordered, so we get the initial 3 values that hold
    metadataAmount, mapRow and mapCol*/

    *metadataAmount = x;
    *mapRow = y;
    *mapCol = z;

    table = (int **) malloc(sizeof(int *) * (*metadataAmount)); /*malloc a metadata table*/

    for(i = 0 ; i < (*metadataAmount) ; i++)
    {
        table[i] = (int *) malloc(sizeof(int) * 3); /*Going to have three columns, and metadataamount number of rows*/
    }

    do 
    {
        fscanf(f, "%d %d %d", &x, &y, &z);

        if (z == 0) /*We found the player location, so we put it into first row*/
        {
            table[0][0] = x;
            table[0][1] = y;
            table[0][2] = z;
        }
        else if (z == 2) /*We found the goal location, so we put it into second row*/
        {
            table[1][0] = x;
            table[1][1] = y;
            table[1][2] = z;
        }
        else if (z == 1) /*We found the snake location, so we put it into third row*/
        {
            table[2][0] = x;
            table[2][1] = y;
            table[2][2] = z;
        }
        else
        { /*Everything else can just go inside here*/
            table[count][0] = x;
            table[count][1] = y;
            table[count][2] = z;
            count = count + 1;
        }
    } while (count < *metadataAmount);

    *metadataTable = table;
    fclose(f);
}

int fileExists(char* fileName) /*Checks if file exists, if it exists then return 1*/
{
    int returnVal = 0;
    FILE* f = fopen(fileName, "r");
    if (f == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        fclose(f);
        returnVal = 1; 
    }
    return returnVal;
}