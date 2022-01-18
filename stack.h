#ifndef STACK_H
#define STACK_H

#define MIN_SIZE 0
#define MIN_TOP -1

typedef struct {

    int top;
    int size;
    int* items;
} Stack;

Stack* createStack(int size);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
void memcleanStack(Stack* stack); 
#endif
