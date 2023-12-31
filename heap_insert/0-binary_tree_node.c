#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 *
 * Return: Pointer to the newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node = malloc(sizeof(binary_tree_t));
if (node)
{
node->n = value;
node->parent = parent;
node->left = NULL;
node->right = NULL;
}
return (node);
}
