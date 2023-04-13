#include "monty.h"

/**
* add_data - insert data to stack or queue struct
* @data: int to add
* Return: 0 on success
*/


int add_data(int data)
{
	stack_t *tmp;

	tmp = head;
	tmp->n = data;
	return (0);
}

/**
* findFunc - find right func for opcodes
* @cmdTok: ptr to opcode in monty file
* @argument: arg to opcode in monty file
* @ifInt: 1 if int else -1
* @lineNum: line number in monty file
*/
void findFunc(char *cmdTok, int argument, int ifInt, unsigned int lineNum)
{
	stack_t *head = NULL;
	int i;
	stack_t *new_top = NULL;
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
				if (ifInt < 0)
					handle_errors(5, lineNum);
				new_top = alloc_mem();
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
* @lineNum: line number in monty file
*/

void push(stack_t **top, unsigned int lineNum)
{
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
		head->prev = *top;
		(*top)->prev = NULL;
		(*top)->next = head;
		head = *top;
		return;
	}

}

/**
* pall - print all data in stack or queue data struct
* @stack: ptr to top of stack or queue
* @lineNum: line number in monty file
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
}
