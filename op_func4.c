#include "monty.h"

/**
* rotl - rotate the top value to the bottom on the stack
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void rotl(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp;
	stack_t *tmp2;
	(void)lineNum;

	if (*top == NULL || top == NULL)
		return;

	tmp = *top;
	if (tmp->next != NULL)
	{
		*top = tmp->next;
		(*top)->prev = NULL;
		tmp2 = *top;
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp;
		tmp->prev = tmp2;
		tmp->next = NULL;
	}
}