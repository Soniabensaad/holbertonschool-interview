#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	skiplist_t *head, *res;
	int array[23] = {
		0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 100, 100, 100, 111, 122, 123, 145, 155, 260
	};

	head = create_skiplist(array, 23);
	print_skiplist(head);
	res = linear_skip(head, 123456789);
	printf("Found at index: %p\n", (void *) res);
	free_skiplist(head);
	return (0);
