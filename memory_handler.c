#include "monty.h"

/**
*
*
*/

stack_t *alloc_mem()
{
	stack_t *node;
	node = malloc(sizeof(stack_t));

	if (node == NULL)
		handle_errors(4);
	node->n = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/**
*
*
*/

void free_mem()
{
	stack_t *temp;
	
	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp);
	}
}
