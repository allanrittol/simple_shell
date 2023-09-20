#include "main.h"

/**
 * _implement - function that uses fork and execve to excute a command
 * @cmd: array of commands to be executed
 * @argv: arguments
 * @index: integer value
 *
 * Return: exit status of the child process
 */

int _implement(char **cmd, char **argv, int index)
{
	pid_t child;
	int stat;
	char *command;

	command = path_handler(cmd[0]);
	if (!command)
	{
		_perror(argv[0], cmd[0], index);
		freearray(cmd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(command, cmd, environ) == -1)
		{
			free(command), command = NULL;
			freearray(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray(cmd);
		free(command), command = NULL;
	}
	return (WEXITSTATUS(stat));
}


