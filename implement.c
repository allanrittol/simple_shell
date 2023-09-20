#include "main.h"

/**
 * _implement - function that uses fork and execve to excute a command
 * @cmd: array of commands to be executed
 * @argv: arguments
 *
 * Return: exit status of the child process
 */

int _implement(char **cmd, char **argv)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freearray(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray(cmd);
	}
	return (WEXITSTATUS(stat));
}


