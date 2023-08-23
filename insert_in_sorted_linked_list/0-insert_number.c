#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = number;
    new_node->next = NULL;

    listint_t *current;

    if (*head == NULL || number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current = *head;
    while (current->next != NULL && number > current->next->n)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}
