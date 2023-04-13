#include "monty.h"

/**
* pop - print the value at top of stack
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void pop(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp;

	if (*top == NULL || top == NULL)
		handle_other_errors(1, lineNum);

	tmp = *top;
	*top = tmp->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(tmp);
}
