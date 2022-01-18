#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node_T {
    int data;
    struct Node_T* next;
} Node;

typedef struct LinkedList_T {
    struct Node_T* head;
    struct Node_T* curr;
    struct Node_T* prev;
    int size;
} LinkedList;

LinkedList* createLinkedList(void);

void addNodeToLinkedList(LinkedList* list, int data);

void tranverseLinkedList(LinkedList* list);

void printLinkedList(LinkedList* list);

void removeNodeFromLinkedList(LinkedList* list, int data);

void memcleanLinkedList(LinkedList* list);
#endif
