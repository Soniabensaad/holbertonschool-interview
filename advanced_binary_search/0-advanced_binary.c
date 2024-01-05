#include <stdio.h>

int advanced_binary_recursive(int *array, size_t left, size_t right, int value);

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    return advanced_binary_recursive(array, 0, size - 1, value);
}

/**
 * advanced_binary_recursive - Recursive binary search function
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the current search range
 * @right: Right index of the current search range
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not present
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t i;

    if (left > right)
        return -1;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");

    i = left + (right - left) / 2;

    if (array[i] == value)
    {
        if (i == left || array[i - 1] != value)
            return i;
        else
            return advanced_binary_recursive(array, left, i, value);
    }
    else if (array[i] > value)
        return advanced_binary_recursive(array, left, i, value);
    else
        return advanced_binary_recursive(array, i + 1, right, value);
}
