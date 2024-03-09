#ifndef _LIST_H_
#define _LIST_H_

/* LIBRARIES */

#include <stdlib.h>
#include <string.h>

/**
 * struct List - doubly linked list
 * @str: string - (of malloc)
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 *
 * Description: doubly linked list node
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* PROTOTYPES */

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);
List *create_node(char *str);

#endif /* _LIST_H_ */
