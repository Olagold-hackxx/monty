#include "monty.h"

/**
 * handle_errors - handle all errors while using monty
 * @error_num: error number
 *
 * Description: Handles all errors that occurs
 * when intepreting monty bytecode file(.m extension)
 */
void handle_errors(const unsigned int error_num, ...)
{
	char *opcode_error;
	char *file_name;
	unsigned int line_number;
	va_list(ap);

	va_start(ap, error_num);
	switch (error_num)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			file_name = va_arg(ap, char *);
			fprintf(stderr, "Error: Can't open file %s\n"
					, file_name);
			break;
		case 3:
			line_number = va_arg(ap, unsigned int);
			opcode_error = va_arg(ap, char *);
			fprintf(stderr, "L%u: unknown instruction
				       	%s\n", line_number, opcode_error)
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			line_number = va_arg(ap, unsigned int);
			fprintf(stderr, "L%u: usage: push", line_number);
			break;
		default:
			break;
	}
	exit(EXIT_FAILURE);
}
