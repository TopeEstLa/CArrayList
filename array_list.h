#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

/**
 * Array List
 * A dynamic array list that can store any type of data
 */
typedef struct array_list {
    int capacity;
    int item_size;
    int length;
    void *items;
} Array_List;

/**
 * Create a new array list
 * @param item_size size of each item in the list
 * @param initial_capacity initial capacity of the list
 * @return the Array_List if successful, NULL otherwise
 */
Array_List* array_list_create(int item_size, int initial_capacity);

/**
 * Append an item to the array list
 * @param list the array list
 * @param item the item to append
 * @return the index on the list where the item was appended
 */
int array_list_append(Array_List* list, void* item);

/**
 * Get an item from the array list
 * @param list the array list
 * @param index the index of the item to get
 * @return the item at the index or NULL if error
 */
void* array_list_get(Array_List* list, int index);

/**
 * Remove an item from the array list
 * @param list the array list
 * @param index the index of the item to remove
 * @return 0 if successful, -1 otherwise
 */
int array_list_remove(Array_List* list, int index);

#endif //ARRAY_LIST_H
