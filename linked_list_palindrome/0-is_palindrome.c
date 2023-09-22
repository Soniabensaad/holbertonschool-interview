#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
int is_palindrome(listint_t **head)
{
	listint_t *low = *head, *fast = *head;
	int len = 0;
	int arr[1024];

	if (*head == NULL)
		return (1);
	while (fast != NULL && fast->next != NULL)
	{
		arr[len] = low->n;
		low = low->next;
		fast = fast->next->next;
		len++;
	}
	if (fast != NULL)
		low = low->next;
	while (low != NULL)
	{
		len--;
		if (arr[len] != low->n)
		{
			return (0);
		}
		low = low->next;
	}
	return (1);
}
