#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct linkedlist
{
    struct linkedlist_node *first;
    // TODO: define linked list metadata
    int size; 
};

struct linkedlist_node
{
    // TODO: define the linked list node
    struct linkedlist_node *next;
    int key;
    int value; 
};
typedef struct linkedlist_node linkedlist_node_t;

linkedlist_t *ll_init()
{
    // TODO: create a new linked list

    // We have done this TODO for you as an example of how to use malloc().
    // You might want to read more about malloc() from Linux Manual page.
    // Usually free() should be used together with malloc(). For example, 
    // the linkedlist you are currently implementing usually have free() in the
    // ll_delete() function. Since we are not asking you to implement
    // the ll_delete() function, you will not be using free() in this case.

    // First, you use C's sizeof function to determine
    // the size of the linkedlist_t data type in bytes.
    // Then, you use malloc to set aside that amount of space in memory.
    // malloc returns a void pointer to the memory you just allocated, but
    // we can assign this pointer to the specific type we know we created
    linkedlist_t *list = malloc(sizeof(linkedlist_t));

    // TODO: set metadata for your new list and return the new list

    list->size = 0; 
    list->first = NULL;
    return list;
}

void ll_add(linkedlist_t *list, int key, int value)
{
    // TODO: create a new node and add to the front of the linked list if a
    // node with the key does not already exist.
    // Otherwise, replace the existing value with the new value.
    if (list->first == NULL){
        linkedlist_node_t *curr = malloc(sizeof(linkedlist_node_t)); // Create a new node 
        curr->key = key; 
        curr->value = value;

        list->first = curr;
        list->size += 1;
    }

    linkedlist_node_t *curr = list->first; 

    if (curr->key == key){
        curr->value = value; 
        return;
    }

    // traverse the node, till the last. if meet a node same key, update value. 

    while (curr->next != NULL){
        if (curr->key == key){
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    // add new node

    linkedlist_node_t *new_node = malloc(sizeof(linkedlist_node_t));
    new_node->key = key;
    new_node->value = value;

    curr->next = new_node;
    list->size += 1;
    return;
}

int ll_get(linkedlist_t *list, int key)
{
    // TODO: go through each node in the linked list and return the value of
    // the node with a matching key.
    // If it does not exist, return 0.
    for (linkedlist_node_t *tmp = list->first; tmp != NULL; tmp = tmp->next){
        if (tmp->key == key){
            return tmp->value;
        }
    }
    return 0;
}

int ll_size(linkedlist_t *list)
{
    // TODO: return the number of nodes in this linked list
    return list->size;
}
