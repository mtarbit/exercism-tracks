#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node_t;

node_t *build_tree(int tree_data[], size_t tree_size);
int *sorted_data(node_t *tree);

#endif
