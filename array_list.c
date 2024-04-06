#include "array_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array_List* array_list_create(int item_size, int initial_capacity) {
    Array_List* list = malloc(sizeof(Array_List));
    if (list == NULL) {
        printf("CArrayList: Failed to allocate memory for list\n");
        return NULL;
    }

    if (item_size <= 0) {
        printf("CArrayList: Item size must be greater than 0\n");
        free(list);
        return NULL;
    }

    if (initial_capacity <= 0) {
        printf("CArrayList: Initial capacity must be greater than 0\n");
        free(list);
        return NULL;
    }

    list->item_size = item_size;
    list->capacity = initial_capacity;
    list->length = 0;
    list->items = malloc(item_size * initial_capacity);

    if (!list->items) {
        printf("CArrayList: Failed to allocate memory for items\n");
        free(list);
        return NULL;
    }

    return list;
}

int array_list_append(Array_List* list, void* item) {
    if (list == NULL) {
        printf("CArrayList: List is NULL\n");
        return -1;
    }

    if (item == NULL) {
        printf("CArrayList: Item is NULL\n");
        return -1;
    }

    if (list->length >= list->capacity) {
        list->capacity *= 2;
        void* items = realloc(list->items, list->item_size * list->capacity);
        if (!items) {
            printf("CArrayList: Failed to reallocate memory for items\n");
            return -1;
        }

        list->items = items;
    }

    int index = list->length++;
    int* dest = list->items + (index * list->item_size);

    memcpy(dest, item, list->item_size);

    return index;
}

void* array_list_get(Array_List* list, int index) {
    if (list == NULL) {
        printf("CArrayList: List is NULL\n");
        return NULL;
    }

    if (index < 0 || index >= list->length) {
        printf("CArrayList: Index out of bounds\n");
        return NULL;
    }

    return list->items + (index * list->item_size);
}

int array_list_remove(Array_List* list, int index) {
    if (list == NULL) {
        printf("CArrayList: List is NULL\n");
        return -1;
    }

    if (index < 0 || index >= list->length) {
        printf("CArrayList: Index out of bounds\n");
        return -1;
    }

    int* src = list->items + ((index + 1) * list->item_size);
    int* dest = list->items + (index * list->item_size);
    int count = list->length - index - 1;

    memmove(dest, src, list->item_size * count);
    list->length--;

    return 0;
}