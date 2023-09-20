#include "main.h"

/**
 * main - main function for the simple shell
 * @argc: number of arguments
 * @argv: arguments to be used
 *
 * Return: (0) always if successful
 */

int main(int argc, char **argv)
{
	char *lineptr = NULL, **command = NULL;
	int i, stat = 0;
	(void) argc;
	(void) argv;

	while (1)
	{
		lineptr = read_input();
		if (lineptr == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		command = tokenizer(lineptr);
		if (!command)
			continue;
		for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			free(command[i]), command[i] = NULL;
		}
		free(command), command = NULL;
	}

}
