#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head) {
    listint_t *slowPtr;
    listint_t *fastPtr;
    listint_t *secondHalf = NULL;
    listint_t *prev = NULL;

    if (*head == NULL || (*head)->next == NULL) {
        return 1; /* An empty list or a single-node list is considered a palindrome */
    }

    slowPtr = *head;
    fastPtr = *head;

    /* Find the middle of the linked list using the slow and fast pointers */
    while (fastPtr != NULL && fastPtr->next != NULL) {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    /* Reverse the second half of the linked list */
    prev->next = NULL;
    while (slowPtr != NULL) {
        listint_t *next = slowPtr->next;
        slowPtr->next = secondHalf;
        secondHalf = slowPtr;
        slowPtr = next;
    }

    /* Compare the first half with the reversed second half */
    listint_t *firstHalf = *head;
    while (firstHalf != NULL && secondHalf != NULL) {
        if (firstHalf->n != secondHalf->n) {
            return 0; /* Not a palindrome */
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1; /* It's a palindrome */
}

// Rest of your code, including the main function and other utility functions
// Function to insert a new node at the end of the linked list
void insertEnd(listint_t** head, int data) {
    listint_t* newNode = (listint_t*)malloc(sizeof(listint_t));
    newNode->n = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    listint_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}
