#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node_T {

    int data;
    struct Node_T* next;
} Node;

Node* createLinkedList() {

    Node* list = (Node*)malloc(sizeof(Node));
    
    if (list == NULL) {
        printf("Failed to create Linked List. Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    return list;
}

#endif
