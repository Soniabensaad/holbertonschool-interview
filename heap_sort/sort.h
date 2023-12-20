#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *array, int i, int j, const int r_size);
void largest_number(int *array, size_t size, int i, const int r_size);
void heap_sort(int *array, size_t size);

#endif
