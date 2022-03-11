#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>

#define MIN_SIZE 0

typedef struct MAP_ITEM_T {

    char* key;
    int value;
    struct MAP_ITEM_T* next;

} MapItem;

typedef struct MAP_T {

    int size;
    MapItem* head;
    MapItem* curr;
    MapItem* prev; 

} Map;

Map* createMap(void);
void addItem(Map* map, const char* key, int value);
void printMap(Map* map);
int getItem(Map* map, const char* key);
void memcleanMap(Map* map);

#endif
