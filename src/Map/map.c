#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "map.h"

Map* createMap(void) {

    Map* map = (Map*)calloc(1, sizeof(Map));

    if (map == NULL) {
        printf("Failed to create Map. Mem alloc Failed");
        exit(EXIT_FAILURE);
    }

    map->size = MIN_SIZE;
    map->head = NULL;
    map->prev = NULL;
    map->curr = NULL;

    return map;
}

void addItem(Map* map, const char* key, int data) {
    
    if (map == NULL) {
        printf("Failed to create Map. Map is NULL");
        exit(EXIT_FAILURE);
    }

    MapItem* item = (MapItem*)calloc(1, sizeof(MapItem));

    if (item == NULL) {
        printf("Failed to add to Map. Mem Alloc Failed");
        exit(EXIT_FAILURE);
    }

    item->key = (char*)calloc(strlen(key)+1, sizeof(char));
   
    if (item->key == NULL) {
        printf("Failed to add to Map. Mem Alloc Failed");
        exit(EXIT_FAILURE);
    }

    strcpy(item->key,key);
    item->key[strlen(item->key)] = '\0'; 
    item->value = data;
    item->next = NULL;

    if (map->head == NULL) {
        map->head = item;
    } else {
        
        map->curr = map->head;

        while (map->curr->next != NULL)
            map->curr = map->curr->next;
        
        map->curr->next = item;
    }

    map->curr = NULL;
    item = NULL;
   
    map->size++;

}

void printMap(Map* map) {

    if (map == NULL) {
        printf("Failed to create Map. Map is NULL");
        exit(EXIT_FAILURE);
    }

    map->curr = map->head;

    while (map->curr != NULL) {
        printf("Item Key is %s and value is %d\n", map->curr->key, map->curr->value);
        map->curr = map->curr->next;
    }
        
    map->curr = NULL;
    
}

int getItem(Map* map, const char* key) {
    
    if (map == NULL) {
        printf("Failed to create Map. Map is NULL");
        exit(EXIT_FAILURE);
    }

    if (strlen(key) == 0) {
        printf("Key is required");
        exit(EXIT_FAILURE);
    }

    map->curr =map->head;

    while (map->curr->next != NULL && strcmp(map->curr->key, key) != 0) {
        map->curr = map->curr->next;
    }

    if (map->curr == NULL) {
        printf("Key %s was not found in Map Keys.", key); 
        exit(EXIT_FAILURE);
    }

    int val = map->curr->value;
    map->curr = NULL;
    return val;
}

void memcleanMap(Map* map) {

    if (map == NULL) {
        printf("Failed to create Map. Map is NULL");
        exit(EXIT_FAILURE);
    }

    map->curr = map->head;
    
    while (map->curr->next != NULL) {
        map->prev = map->curr;
        map->curr = map->curr->next;
        free(map->prev->key);
        free(map->prev);
    }

    free(map->curr->key);
    free(map->curr);

    map->prev = NULL;
    map->head = NULL;
    map->curr = NULL;
    map->size = 0;

    free(map);
}
