#include "main.h"

/**
 * path_handler - function that handles the PATH and also searches
 * for a command in the PATH environment variable
 * @cmd:
 *
 * Return: first valid path found on success, NULL otherwise
 *
 */

char *path_handler(char *cmd)
{
	char *envpath, *command, *fold;
	struct stat s;
	int n;

	for (n = 0; cmd[n]; n++)
	{
		if (cmd[n] == '/')
		{
			if (stat(cmd, &s) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	envpath = our_getenv("PATH");
	if (!envpath)
		return (NULL);
	fold = strtok(envpath, ":");
	while (fold)
	{
		command = malloc(_strlen(fold) + _strlen(cmd) + 2);
		if (command)
		{
			_strcpy(command, fold);
			_strcat(command, "/");
			_strcat(command, cmd);
			if (stat(command, &s) == 0)
			{
				free(envpath);
				return (command);
			}
			 free(command);
			 command = NULL;

			 fold = strtok(NULL, ":");
		}
	}
	free(envpath);
	return (NULL);
}


