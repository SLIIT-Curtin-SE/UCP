#ifndef GAME_H
#define GAME_H

void initializeMap(char*** mapArray, int** metadataArray, int metadataAmount ,int mapRow, int mapCol, char** player);

void displayMap(char** mapArray, int mapRow, int mapCol, int visibility, int* playerRowLoc, int* playerColLoc);

void rotatePlayer(char* player, char input);

void movePlayer(char*** mapArray, char** player , char input, int mapCol, int mapRow, int* playerRowLoc, int* playerColLoc, int goalRowLoc, int goalColLoc, int* won);

#endif