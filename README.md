
--

# Msibi ADT ( ABSTRACT DATA TYPES)

Author: Philane Msibi

--

## Description

This is some sort of "library" or "reference guide" to C Devs on how to implement basic Data Structure operations on their future applications. 
As I'm continuing with my C/C++ journey, some of these data structure, which are dynamic, are not present in C.
This guide contains almost all the popular data structures you can think of.

--

## Supported Data Structures

- Stack
- Singular Linked list

--

## WIP Data Structure

- Maps
- Sets
- Graphs

--

## Stack Snippet

```C
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
```
--

## Linked List Snippet

```C
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

```

## Contributions

Should you wish to contribute, PRs are accepted and discusses also.
