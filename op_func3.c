
#include "monty.h"

/**
* divd - divide the two value at top of stack and replace with result
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void divd(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp1;
	stack_t *tmp2;

	if (*top == NULL || top == NULL)
		handle_other_errors(5, lineNum);

	tmp1 = *top;
	tmp2 = (*top)->next;
	if (tmp1->n == 0)
		handle_other_errors2(2, lineNum);
	if (tmp2 != NULL)
	{
		tmp2->n = tmp2->n / tmp1->n;
		pop(top, lineNum);
	}
	else
		handle_other_errors(5, lineNum);
}

/**
* mul - multiply the two value at top of stack and replace with result
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void mul(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp1;
	stack_t *tmp2;

	if (*top == NULL || top == NULL)
		handle_other_errors(6, lineNum);

	tmp1 = *top;
	tmp2 = (*top)->next;
	if (tmp2 != NULL)
	{
		tmp2->n = tmp1->n * tmp2->n;
		pop(top, lineNum);
	}
	else
		handle_other_errors(6, lineNum);
}

/**
* mod - computes the rest of the division of the second top element
* of the stack by the top element of the stack.
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void mod(stack_t **top, unsigned int lineNum)
{
	stack_t *tmp1;
	stack_t *tmp2;

	if (*top == NULL || top == NULL)
		handle_other_errors2(1, lineNum);

	tmp1 = *top;
	tmp2 = (*top)->next;
	if (tmp1->n == 0)
		handle_other_errors2(2, lineNum);
	if (tmp2 != NULL)
	{
		tmp2->n = tmp2->n % tmp1->n;
		pop(top, lineNum);
	}
	else
		handle_other_errors2(1, lineNum);
}

/**
* pchar - print the ascii value of int at top of stack
* @top: ptr to stack struct
* @lineNum: line number in monty file
*/

void pchar(stack_t **top, unsigned int lineNum)
{
	if (*top == NULL)
		handle_other_errors2(4, lineNum);
	if ((*top)->n >= 128 || (*top)->n <= 0)
		handle_other_errors2(3, lineNum);
	printf("%c\n", (*top)->n);
}
