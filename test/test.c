#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[50] = "Hello";
	char *token;
	int lent;

	token = strtok(str, " ");
	lent = strlen(token);
	if (strcmp(token, "Hello") == 0)
		printf("%s %d\n", token, lent);
	return (0);
}