#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t size = 0;

    if (tree)
    {
        size = 1;
        size += binary_tree_size(tree->left);
        size += binary_tree_size(tree->right);
    }

    return (size);
}

/**
 * heapify_up - Rebalances the heap by moving the newly inserted node up.
 * @heap: Pointer to the root of the heap.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(heap_t **heap, heap_t *node)
{
    int temp;

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    if (!node->parent)
        *heap = node;
}
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

    parent = *root;
    while (parent->left)
    {
        if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    heapify_up(root, new_node);

    return (new_node);
}
