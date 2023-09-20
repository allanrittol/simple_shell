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
	(void) argv;
	(void) index;
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, stat);
	else if (_strcmp(cmd[0], "env") == 0)
		env_builtin(cmd, stat);
}

/**
 * exit_shell - function that exits the shell
 * @cmd: input string
 * @stat: shell status
 *
 * Return: nothing
 */
void exit_shell(char **cmd, int *stat)
{
	freearray(cmd);
	exit(*stat);
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
