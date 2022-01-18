/*
 * Linked List Struct Impementation Definitions
 * Author: Philane Msibi
 */

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

LinkedList* createLinkedList(void) {

    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
        
    if (list == NULL) {
        printf("Failed to create Linked List. Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->curr = NULL;
    list->prev = NULL;
    list->size = 0;

    return list;
}

void addNodeToLinkedList(LinkedList* list, int data) {

    if (list == NULL) {
        printf("Failed to add node. List is NULL\n");
        exit(EXIT_FAILURE);
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        tranverseLinkedList(list);
        list->prev = NULL;
        list->curr->next = node;
        list->curr = NULL;
    }

    node = NULL;

    list->size++;
}

void tranverseLinkedList(LinkedList* list) {

    list->curr = NULL;
    list->prev = NULL;

    if (list->head == NULL) {
        printf("Failed to tranverse Linked List.\n");
       exit(EXIT_FAILURE); 
    }
   
    list->curr = list->head;

    while (list->curr->next != NULL) {
        list->prev = list->curr;
        list->curr = list->curr->next;
    }
}

void printLinkedList(LinkedList* list) {

    list->curr = NULL;
    list->prev = NULL;

    list->curr = list->head;

    while (list->curr != NULL) {
        printf("Node  %d\n", list->curr->data);
        list->curr = list->curr->next;
    }
}



void removeNodeFromLinkedList(LinkedList* list, int data) {

    if (list == NULL) {
        printf("Failed to remove node. Linked List is NULL");
        exit(EXIT_FAILURE);
    }

    if (list->head == NULL) {
        printf("Failed to remove node. Linked List is Empty.");
        exit(EXIT_FAILURE);
    }

    if (list->head->next == NULL && list->head->data == data) {
        free(list->head);
        list->head = NULL;
        printf("Item removed from LinkedList");
        return;
    }

    list->curr = NULL;
    list->prev = NULL;

    list->curr = list->head;

    while (list->curr->next != NULL && list->curr->data != data) {
        list->prev = list->curr;
        list->curr = list->curr->next;
    }

    if (list->curr->next == NULL) {
        printf("Failed to remove node. Item not found in Linked List.");
        return;
    }

    list->curr = list->curr->next;

    free(list->prev->next);
    list->prev->next = list->curr;
    printf("Item removed from LinkedList");
}

void memcleanLinkedList(LinkedList* list) {
    
    if (list != NULL ) {
        free(list->head);
        free(list->prev);
        free(list->curr);
        
        list->head = NULL;
        list->curr = NULL;
        list->prev = NULL;
        list->size = 0;
        free(list);
    }
    
}
