#ifndef LLIST_H
#define LLIST_H

typedef struct LinkedListNode 
{
    void* value;
    struct LinkedListNode* next;

} LinkedListNode;

typedef struct LinkedList
{
    LinkedListNode* head;
} LinkedList;

void initializeLinkedList(LinkedList** undoStack);

void insertFirst(int calcDisplay, LinkedList** undoStack);

void freeUndoStack(LinkedList* undoStack);

void printStack(LinkedList** undoStack, char* filename, int total);

#endif