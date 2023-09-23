#include "main.h"

/**
 * unset_env_var - function to unset an env variable
 * @name: name of the env variable
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env_var(const char *name)
{
	int i, j, f = 0;
	char *entry;

	for (i = 0; environ[i] != NULL; i++)
	{
		entry = environ[i];
		if (strcmp(entry, name) == 0 && entry[strlen(name)] == '=')
		{
			free(environ[i]);
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			break;
		}
	}
	return (f ? 0 : -1);
}

/**
 * environ_size - function to determins size of environ array
 * Return: size of environ
 */
int environ_size(void)
{
	int size = 0;

	while (environ[size] != NULL)
		size++;
	return (size);
}
