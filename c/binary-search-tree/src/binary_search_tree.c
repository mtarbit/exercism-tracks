#include <stdlib.h>
#include "binary_search_tree.h"

static node_t *build_node(int data) {
    node_t *n = malloc(sizeof(node_t));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

static void extend_tree(node_t *tree, int data) {
    if (data > tree->data) {
        if (tree->right == NULL) {
            tree->right = build_node(data);
        } else {
            extend_tree(tree->right, data);
        }
    } else {
        if (tree->left == NULL) {
            tree->left = build_node(data);
        } else {
            extend_tree(tree->left, data);
        }
    }
}

node_t *build_tree(int tree_data[], size_t tree_size) {
    node_t *tree = build_node(tree_data[0]);

    for (size_t i = 1; i < tree_size; i++) {
        extend_tree(tree, tree_data[i]);
    }

    return tree;
}

static int get_data(int **result, int length, node_t *node) {
    if (node->left) {
        length = get_data(result, length, node->left);
    }

    *result = realloc(*result, sizeof(int) * (length + 1));
    (*result)[length++] = node->data;

    if (node->right) {
        length = get_data(result, length, node->right);
    }

    return length;
}

int *sorted_data(node_t *tree) {
    int *result = NULL;
    int length = 0;

    get_data(&result, length, tree);

    return result;
}
