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

/**
* rotr - rotate the bottom value to the top on the stack
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void rotr(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp;
	stack_t *tmp2;
	(void)lineNum;

	if (*top == NULL || top == NULL)
		return;

	tmp = *top;
	tmp2 = (*top)->next;
	if (tmp2 != NULL)
	{
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
		}
		tmp2->prev->next = NULL;
		tmp->prev = tmp2;
		tmp2->prev = NULL;
		tmp2->next = tmp;
		*top = tmp2;
	}
}

/**
* stack - set type of data struct to stack
* @top: ptr to top of stack struct
* @lineNum: line number in monty file
*/
void stack(stack_t **top, unsigned int lineNum)
{
	(void)top;
	(void)lineNum;
	format = 0;
}

/**
* queue - set type of data struct to stack
* @top: ptr to top of queue struct
* @lineNum: line number in monty file
*/
void queue(stack_t **top, unsigned int lineNum)
{
	(void)top;
	(void)lineNum;
	format = 1;
}

/**
* push2queue - insert to the top of queue
* @top: ptr to top of queue struct
* @lineNum: line number in monty file
*/
void push2queue(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp;
	(void)(lineNum);

	if (!top || !*top)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *top;
		return;
	}
	else
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *top;
		(*top)->next = NULL;
		(*top)->prev = tmp;
	}
}
