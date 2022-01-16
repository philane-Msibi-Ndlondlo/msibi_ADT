#include <stdio.h>
#include "stack.h"

int main(int argc, const char *argv[]) {
    
    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    int item = peek(stack);
    printf("%d", item);
    printf("%d was popped so top is now %d", pop(stack), stack->top);
    return 0;
}
