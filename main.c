#include "main.h"
/**
 * main - main function for the simple shell
 * @ac: number of arguments
 * @av: arguments to be used
 *
 * Return: (0) always if successful
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status;
	(void) ac;

	while (1)
	{
		line = read_line();

		command = tokenizer(line);

		status = _execute(command, argv);
	}
}
