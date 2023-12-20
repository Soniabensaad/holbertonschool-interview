#include "sort.h"

/**
 * swap - Swap in the array
 * @array: the array for swap him values.
 * @i: First index
 * @j: Second index
 * @r_size: Length size
 */
void swap(int *array, int i, int j, const int r_size)
{
	int tmp;
	(void)r_size;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * largest - Find largest of two sides
 * @array: The array for sort
 * @size: Length of the min element
 * @i: Largest.
 * @r_size: Right swap
 */
void largest_number(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != i)
	{
		swap(array, i, largest, r_size);
		largest_number(array, size, largest, r_size);
	}
}

/**
 * heap_sort - Make a heap
 * @array: Address of the first element
 * @size: Length of the array
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		largest_number(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i, r_size);
		largest_number(array, i, 0, r_size);
	}
}
