#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * to measure the size
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t r = 0;

	if (tree == NULL)
		return (0);

	r++;
	r += binary_tree_size(tree->left);
	r += binary_tree_size(tree->right);

	return (r);
}

/**
 * change - change two value
 * @parent : 1st value
 * @node : 2sd value
*/
void change(int *parent, int *node)
{
	int p;

	p = *node;
	*node = *parent;
	*parent = p;
}
/**
 * find_parent - find the parent of the node to insert
 * @tree : tree to search
 * @index : index of the tree
 * @size : size of the tree
 *
 * Return: the parent of the node to insert
*/
heap_t *find_parent(heap_t *tree, int index, int size)
{
	heap_t *l, *r;

	if (index == size)
		return (tree);

	if (index > size)
		return (NULL);

	l = find_parent(tree->left, 2 * index + 1, size);
	r = find_parent(tree->right, 2 * index + 2, size);

	if (l)
		return (l);
	else if (r)
		return (r);
	else
		return (NULL);

}
/**
 * insert_node - insert the node
 * @tree : tree into insert the node
 * @new : node to insert
 *
 * Return: tree
*/
heap_t *insert_node(heap_t *tree, heap_t *new)
{
	int size = binary_tree_size(tree);
	heap_t *parent = find_parent(tree, 0, ((size - 1) / 2));

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	return (parent);

}
/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root : double pointer to the root node of the Heap
 * @value : value to insert
 *
 * Return: pointer to the inserted node or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = binary_tree_node(NULL, value), *parent;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = new;
		return (new);
	}
	parent = insert_node(*root, new);
	new->parent = parent;

	while (new->parent && new->n > new->parent->n)
	{
		change(&new->parent->n, &new->n);
		new = new->parent;
	}
	return (new);
}
