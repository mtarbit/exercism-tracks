#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef size_t ll_data_t;

struct node_item {
    struct node_item *prev;
    struct node_item *next;
    ll_data_t data;
};

struct list_item {
    struct node_item *head;
    struct node_item *tail;
};

struct list_item **new_list();
void delete_list(struct list_item **);
bool is_list_empty(struct list_item **);
bool push(struct list_item **, ll_data_t);
ll_data_t pop(struct list_item **);
bool unshift(struct list_item **, ll_data_t);
ll_data_t shift(struct list_item **);

#endif
