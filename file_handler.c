#include "monty.h"

/**
* open_readfile - open file
* @argv: 1st cmd line argument
* Return: 0 on success
*/

int open_readfile(char **argv)
{
	unsigned int lineNum = 0, lineLength = 150;
	FILE *fp;
	char *line;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		handle_errors(2, argv[1]);
	line = (char *)malloc(sizeof(char) * lineLength);
	if (line == NULL)
		handle_errors(4);
	while (fgets(line, lineLength, fp))
	{
		lineNum++;
		line[strcspn(line, "\n")] = '\0';
		if (strlen(line) > 0)
			interpretLine(line, lineNum);
	}
	free(line);
	fclose(fp);
	return (0);
}

/**
* interpretLine - interpret line to find opcodes
* @line: line read
* @lineNum: line number
* Return: 0 on success
*/

int interpretLine(char *line, unsigned int lineNum)
{
	char *cmdToken, *argToken;
	int argument;
	int ifInt;
	unsigned int line_num = lineNum;

	cmdToken = strtok(line, " ");
	if (cmdToken != NULL)
	{
		if (cmdToken[0] == '#')
			return (0);
		argToken = strtok(NULL, " ");
		if (argToken != NULL)
		{
			if (ifisdigit(argToken) != 0)
			{
				argument = atoi(argToken);
				ifInt = 1;
			}
			else if (argToken[0] == '-')
			{
				argToken[0] = '0';
				if (ifisdigit(argToken) != 0)
				{
					argument = atoi(argToken) * -1;
					ifInt = 1;
				}
				else
					ifInt = -1;
			}
			else
				ifInt = -1;
		}
		else
			ifInt = -1;
		findFunc(cmdToken, argument, ifInt, line_num);
		return (0);
	}
	else
		return (0);
}

/**
* ifisdigit - check if string is digit
* @string: string to check
* Return: 1 on success 0 if not digit
*/

int ifisdigit(char *string)
{
	size_t i;

	for (i = 0; i < strlen(string); i++)
	{
		if (isdigit(string[i]))
			;
		else
			return (0);
	}
	return (1);
}
