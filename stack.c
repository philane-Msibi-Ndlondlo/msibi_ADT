/*
 * Stack Struct Impementation Definitions
 * Author: Philane Msibi
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(int size){
    
    if (size <= MIN_SIZE) {
        printf("Failed to create stack. Size must be greater than 0");
        exit(EXIT_FAILURE);
    }   

    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL) {
         printf("Failed to allocate stack memory.");
         exit(EXIT_FAILURE);
    }

    stack->top = MIN_TOP;
    stack->size = size;
    stack->items = (int*)calloc(stack->size, sizeof(int));

    if (stack->items == NULL) {
        printf("Failed to create stack. Mem Alloc Failed");
        exit(EXIT_FAILURE);
    }

    return stack;
}

void push(Stack* stack, int item) {
    
    if (!isFull(stack)) {
        stack->items[++stack->top] = item;
    } else {
        printf("Failed to push to stack. Stack Overflow");
        exit(EXIT_FAILURE);
    }
    printf("Item %d pushed to stack\n", stack->items[stack->top]);
}

int pop(Stack* stack) {

    if (isEmpty(stack)) {
        printf("Failed to pop on Stack. Stack Underflow");
        exit(EXIT_FAILURE);
    }
    
    return stack->items[stack->top++];
}

int peek(Stack* stack) {

    if (isEmpty(stack)) {
        printf("Failed to peek. Stack Underflow");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == MIN_TOP;
}

int isFull(Stack* stack){
    return stack->top == (stack->size - 1);
}

void memcleanStack(Stack* stack) {
    
    if (stack != NULL) {
        free(stack->items);
        stack->items = NULL;
        stack->size = MIN_SIZE;
        free(stack);
        stack = NULL;
    }
    
}
