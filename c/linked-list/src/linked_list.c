#include <stdlib.h>
#include "linked_list.h"


// To anyone reading this, I'm not sure why the tests for this exercise
// expect list_item to be a pointer-to-a-pointer everywhere, which seems
// to add an extra layer of unnecessary indirection. It was confusing
// enough that I resorted to peeking at the exercise source here:
// https://github.com/exercism/c/blob/master/exercises/linked-list/src/example.c
//
// I notice that the implementation there ignores this part of the introduction
// for some reason, so maybe that's something to do with it:
//
// "Implement a Node to hold a value and pointers to the next and previous nodes.
// Then implement a List which holds references to the first and last node..."
//
// It also seems odd that we're expected to use a `struct list_item` rather
// than a typedef to a `list_item_t` or whatever.


static struct node_item *new_item(ll_data_t data) {
    struct node_item *item = malloc(sizeof(struct node_item));
    item->prev = NULL;
    item->next = NULL;
    item->data = data;
    return item;
}

struct list_item **new_list() {
    struct list_item **list_ptr = malloc(sizeof(struct list_item *));
    struct list_item *list = malloc(sizeof(struct list_item));
    list->head = NULL;
    list->tail = NULL;
    *list_ptr = list;
    return list_ptr;
}

static void delete_item(struct node_item *item) {
    free(item);
}

void delete_list(struct list_item **list_ptr) {
    while (!is_list_empty(list_ptr)) {
        pop(list_ptr);
    }
    free(*list_ptr);
    free(list_ptr);
}

bool is_list_empty(struct list_item **list_ptr) {
    return (list_ptr == NULL || *list_ptr == NULL || (*list_ptr)->head == NULL);
}

bool push(struct list_item **list_ptr, ll_data_t data) {
    if (list_ptr == NULL) {
        return false;
    }

    struct list_item *list = *list_ptr;
    struct node_item *item = new_item(data);
    struct node_item *tail = list->tail;

    if (tail == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        tail->next = item;
        item->prev = tail;
        list->tail = item;
    }

    return true;
}

bool unshift(struct list_item **list_ptr, ll_data_t data) {
    if (list_ptr == NULL) {
        return false;
    }

    struct list_item *list = *list_ptr;
    struct node_item *item = new_item(data);
    struct node_item *head = list->head;

    if (head == NULL) {
        list->head = item;
        list->tail = item;
    } else {
        head->prev = item;
        item->next = head;
        list->head = item;
    }

    return true;
}

ll_data_t pop(struct list_item **list_ptr) {
    struct list_item *list = *list_ptr;
    struct node_item *tail = list->tail;
    struct node_item *prev = tail->prev;
    ll_data_t data  = tail->data;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = prev;
        prev->next = NULL;
    }

    delete_item(tail);

    return data;
}

ll_data_t shift(struct list_item **list_ptr) {
    struct list_item *list = *list_ptr;
    struct node_item *head = list->head;
    struct node_item *next = head->next;
    ll_data_t data  = head->data;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = next;
        next->prev = NULL;
    }

    delete_item(head);

    return data;
}
