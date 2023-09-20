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
	char *lineptr = NULL, **cmd = NULL;
	int stat = 0, index = 0;
	(void) argc;

	while (1)
	{
		lineptr = read_input();
		if (lineptr == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		index++;
		cmd = tokenizer(lineptr);
		if (!cmd)
			continue;

		if (check_builtin(cmd[0]))
			builtin_handler(cmd, argv, &stat, index);
		else
			stat = _implement(cmd, argv, index);
	}
}

