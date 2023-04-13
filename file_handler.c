#include "monty.h"

/**
* open_file - open file
* @argv: 1st cmd argument
* Return: 
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
	while(fgets(line, lineLength, fp))
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

int interpretLine(char *line, unsigned int lineNum)
{
	char *cmdToken, *argToken;
	int argument;
	unsigned int line_num = lineNum;

	cmdToken = strtok(line, " ");
	if (cmdToken != NULL)
	{
		argToken = strtok(NULL, " ");
		if (argToken != NULL)
		{
			if (isdigit(*argToken) != 0)
				argument = atoi(argToken);
			else
				argument = -1;
		}
		else
			argument = -1;
		findFunc(cmdToken, argument, line_num);
		return (0);
	}
	else
		return (0);
}
