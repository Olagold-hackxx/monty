#ifndef MONTY_H
#define MONTY_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* 
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/*Stack and Queue Opcodes Function*/
void findFunc(char *, int, unsigned int);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
int add_data(int data);

/*Errors Handlers*/
void handle_errors(const unsigned int error_num, ...);

/*File Handlers*/
int open_readfile(char **);
int interpretLine(char *, unsigned int);


/*Memory Allocations*/
stack_t *alloc_mem();
void free_mem();


#endif /*MONTY_H*/
