#include "main.h"
/**
 * check_builtin - function that checks if inputed command is a
 * built-in command
 * @cmd: string to be checked
 *
 * Return: 1 if successful, 0 if unsuccessful
 */
int  check_builtin(char *cmd)
{
	char *builtin[] = {"exit", "env", "setenv", "cd", NULL};
	int j;

	for (j = 0; builtin[j]; j++)
	{
		if (_strcmp(cmd, builtin[j]) == 0)
			return (1);
	}
	return (0);
}

/**
 * builtin_handler - function that handles builtin commands
 * @cmd: input string
 * @argv: argument list
 * @stat: shell status
 * @index: param index
 *
 * Return: nothing
 */
void builtin_handler(char **cmd, char **argv, int *stat, int index)
{
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, argv, stat, index);
	else if (_strcmp(cmd[0], "env") == 0)
		env_builtin(cmd, stat);
}

/**
 * exit_shell - function that exits the shell
 * @cmd: input string
 * @stat: shell status
 * @argv: argument list
 * @index: param index
 *
 * Return: nothing
 */
void exit_shell(char **cmd, char **argv, int *stat, int index)
{
	int exit_val = (*stat);
	char *i, message[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (positive_num(cmd[1]))
		{
			exit_val = _atoi(cmd[1]);
		}
		else
		{
			i = _iota(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, i, _strlen(i));
			write(STDERR_FILENO, message, _strlen(message));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(i);
			freearray(cmd);
			(*stat) = 2;
			return;
		}
	}

	freearray(cmd);
	exit(exit_val);
}

/**
 * env_builtin - function that handles the env built in command
 * @cmd: input string
 * @stat: shell status
 *
 * Return: nothing
 */
void env_builtin(char **cmd, int *stat)
{
	int j;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(cmd);
	(*stat) = 0;
}
