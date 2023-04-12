#include "monty.h"
stack_t *head = NULL;

/*
* main - main function
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		handle_errors(1);
	open_readfile(argv);
	free_mem();
	return (0);
}