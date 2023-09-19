#include "main.h"

/**
 * read_input - function that reads the input from user
 *
 * Return: pointer
 */

char *read_input(void)
{
	char *lineptr = NULL;
	size_t length = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(#Paullan) $ ", 14);

	n = getline(&lineptr, &length, stdin);
	if (n == -1)
	{
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}
