#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

int main(int argc, const char *argv[]) {
    
    Stack* stack = createStack(5);
    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    
    int item = peek(stack);
    printf("%d", item);
    printf("%d was popped so top is now %d\n\n", pop(stack), stack->top);
    
    memcleanStack(stack); 

    LinkedList* list = createLinkedList();
    
    addNodeToLinkedList(list, 5);
    addNodeToLinkedList(list,10);
    addNodeToLinkedList(list,15);
    addNodeToLinkedList(list, 20);
    addNodeToLinkedList(list, 25);

    printLinkedList(list);
    
    removeNodeFromLinkedList(list, 5);
    
    addNodeToLinkedList(list, 50);
    
    printLinkedList(list);

    memcleanLinkedList(list);
    return 0;
}
