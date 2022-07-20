#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

void initializeLinkedList(LinkedList** undoStack) /*Intialize the LinkedList*/
{
    *undoStack = (LinkedList*)malloc(sizeof(LinkedList));
    (*undoStack)->head = NULL;
}

void insertFirst(char** player, int* playerRowLoc, int* playerColLoc, char** snake, int* snakeRowLoc, int* snakeColLoc,
LinkedList** undoStack) /*Insert these values into the LinkedList*/
{
    LinkedListNode* newNode;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    (*newNode).player = **player; /*Orientation of the player is very important as well*/
    (*newNode).playerMem = *player;
    (*newNode).playerRowLoc = *playerRowLoc;
    (*newNode).playerColLoc = *playerColLoc;
    (*newNode).snakeRowLoc = *snakeRowLoc;
    (*newNode).snakeColLoc = *snakeColLoc;
    (*newNode).snake = *snake;
    (*newNode).next = (*undoStack)->head;

    (*undoStack)->head = newNode;
}

void getFirst(char** player, int* playerRowLoc, int* playerColLoc, char** snake, int* snakeRowLoc, int* snakeColLoc ,
LinkedList** undoStack) /*Get back values from the player*/
{
    if ((*undoStack)->head != NULL)
    {
        LinkedListNode* firstNode = (*undoStack)->head;
        **(player) = ' ';
        *player = (*firstNode).playerMem;
        *playerRowLoc = (*firstNode).playerRowLoc;
        *playerColLoc = (*firstNode).playerColLoc;
        *snakeRowLoc = (*firstNode).snakeRowLoc;
        *snakeColLoc = (*firstNode).snakeColLoc;
        **(snake) = ' ';
        *snake = (*firstNode).snake;
        **snake = '~';
        **player = (*firstNode).player;

        (*undoStack)->head = (*firstNode).next;

        free(firstNode); /*Because we have no use of it, we free it*/
    }
}

void freeUndoStack(LinkedList* undoStack) /*Called at the end of the main, we release all the elements*/
{
    LinkedListNode* node, *nextNode;

    node = (*undoStack).head;

    while(node != NULL) 
    {
        nextNode = (*node).next;
        free(node); /*Lecture slides have us also freeing node.data, but you cant do it since node.data isnt a pointer,
        any valgrind shows no more memory leaks so all is well*/
        node = nextNode;
    }
    free(undoStack); /*Free the pointer to the LinkedList itself*/

}