#include "monty.h"



int add_data(int data)
{
	stack_t *tmp;
	tmp = head;
	tmp->n = data;
	return (tmp->n);
}

/**
* findFunc - find right func for opcodes
*
*/
void findFunc(char *cmdTok, int argument, unsigned int lineNum)
{
	int i;
	stack_t *new_top;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(cmdTok, functions[i].opcode) == 0)
		{
			if (i == 0)
			{
				if (argument < 0)
					handle_errors(5, lineNum);
				new_top = alloc_mem(new_top);
				functions[i].f(&new_top, lineNum);
				add_data(argument);
				return;
			}
			functions[i].f(&head, lineNum);
			return;
		}
	}
	handle_errors(3, lineNum, cmdTok);
}

/**
* push - insert to the top - LIFO, Stack
* @top: stack data structure
* @data: data to insert
*/

void push(stack_t **top, unsigned int lineNum)
{
	(void)(lineNum);
	if (head == NULL)
	{
		head = *top;
		return;
	}
	else
	{
		head->prev = *top;
		(*top)->prev = NULL;
		(*top)->next = head;
		head = *top;
		return;
	}

}

/**
* pall - print all data in stack or queue data struct
* Return: None
*/
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;
	(void)(lineNum);

	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return;
}