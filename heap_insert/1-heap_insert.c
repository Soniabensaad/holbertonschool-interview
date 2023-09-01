#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value) {
    if (!*root) {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    if (value < (*root)->n) {
        (*root)->left = heap_insert(&((*root)->left), value);
    } else {
        (*root)->right = heap_insert(&((*root)->right), value);
    }

    return *root;
}


