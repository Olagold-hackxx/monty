#include "monty.h"
stack_t *head = NULL;
int format = 0;

/**
* main - main function
* @argc: no of cmd line args
* @argv: ptr to args
* Return: 0 on success
*/
int main(int argc, char **argv)
{

	if (argc == 2)
	{
		open_readfile(argv);
		free_mem();
	}
	else
		handle_errors(1);

	return (0);
}
