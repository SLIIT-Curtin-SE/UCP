#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
/*Linkedlist logic is here*/
void initializeLinkedList(LinkedList** undoStackPointer) /*Intialize the LinkedList*/
{
    *undoStackPointer = (LinkedList*)malloc(sizeof(LinkedList));
    (*undoStackPointer)->head = NULL;
}

void insertFirst(int calcDisplay, LinkedList** undoStack) /*Insert these values into the LinkedList,lecture slide code*/
{
    LinkedListNode* newNode;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    (*newNode).value = malloc(sizeof(int));
    *((int *)(*newNode).value) = calcDisplay;
    (*newNode).next = (*undoStack)->head;
    (*undoStack)->head = newNode;
}

void printStack(LinkedList** undoStack, char* filename, int total) /*Print values from linkedlist into the file*/
{
    LinkedListNode* node;
    FILE* f = fopen(filename, "w");
    int elementCount = 0;
    if (total == 0) /*if total is 0, that means no values entered therefore print 0*/
    {
        fprintf(f, "%d", total);
    }
    else
    {
        while ((*undoStack)->head != NULL) /*if not 0, then we'll loop through the elements*/
        {
            elementCount = elementCount + 1;
            node = (*undoStack)->head;
            fprintf(f, "%d", *((int *)(*node).value));
            (*undoStack)->head = (*node).next;
            if ((*undoStack)->head != NULL)
            {
                fprintf(f, "%s", " + ");
            }
            else if (elementCount != 1) /*if element count is not 1 we will print the equal symbol*/
            {
                fprintf(f, "%s", " = ");
            }
            free((*node).value); /*free the pointer since we have no use of it anymore*/
            free(node);
        }
        if (elementCount != 1)
        {
            fprintf(f, "%d\n", total); /*again if element count it not 1 we will print the total*/
        }
    }  
    fclose(f);
    free(*undoStack); /*close the file and free the linkedlist, since the program is shutting down*/
}