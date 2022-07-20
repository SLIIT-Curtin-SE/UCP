#ifndef LLIST_H
#define LLIST_H

typedef struct LinkedListNode 
{
    char player;
    char* playerMem;
    int playerRowLoc;
    int playerColLoc;
    int snakeRowLoc;
    int snakeColLoc;
    char* snake;
    char playerOrientation;
    struct LinkedListNode* next;

} LinkedListNode;

typedef struct 
{
    LinkedListNode* head;
} LinkedList;

void initializeLinkedList(LinkedList** undoStack);

void insertFirst(char** player, int* playerRowLoc, int* playerColLoc, char** snake, int* snakeRowLoc, int* snakeColLoc ,LinkedList** undoStack);

void getFirst(char** player, int* playerRowLoc, int* playerColLoc, char** snake, int* snakeRowLoc, int* snakeColLoc ,LinkedList** undoStack);

void freeUndoStack(LinkedList* undoStack);

#endif