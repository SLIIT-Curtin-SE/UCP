#ifndef GAME_H
#define GAME_H

void initializeMap(char*** mapArray, int** metadataArray, int metadataAmount ,int mapRow, int mapCol, char** player, char** snake);

void displayMap(char** mapArray, int mapRow, int mapCol);

void rotatePlayer(char* player, char input);

void movePlayer(char*** mapArray, char** player , char input, int* playerRowLoc, int* playerColLoc, int goalRowLoc, int goalColLoc, int* won);

#endif