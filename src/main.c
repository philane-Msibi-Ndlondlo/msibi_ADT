#include <stdio.h>
#include <stdlib.h>
#include "Stack/stack.h"
#include "LinkedList/linked_list.h"
#include "Map/map.h"

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
    addNodeToLinkedList(list, 5);

    printLinkedList(list);

    memcleanLinkedList(list);

    Map* map = createMap();
    addItem(map, "score1",54);
    addItem(map, "score2",14);
    addItem(map, "score3",44);
    addItem(map, "score4",52);

    printMap(map);
    printf("%d is the value of key %s", getItem(map, "score2"), "score2");
    memcleanMap(map);
    return EXIT_SUCCESS;
}
