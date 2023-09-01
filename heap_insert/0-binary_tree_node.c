#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (node) {
        node->n = value;
        node->parent = parent;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
