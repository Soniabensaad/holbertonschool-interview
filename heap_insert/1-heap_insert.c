#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * @value: The value to insert into the heap.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (!root)
        return (NULL);

   
    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    
    if (!*root)
        return (*root = new_node);

    
    parent = binary_tree_last_node(*root);

   
    new_node->parent = parent;
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

 
    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        new_node->n ^= new_node->parent->n;
        new_node->parent->n ^= new_node->n;
        new_node->n ^= new_node->parent->n;
        new_node = new_node->parent;
    }

    return (new_node);
}
