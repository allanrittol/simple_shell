#include "main.h"

int main(void)
{
	char *str;
	char *token;

	str = _strdup("This 	is\t	shell\n");

	token = strtok(str, " \t\n");
	printf("%s\n", token);

	return (0);
}
