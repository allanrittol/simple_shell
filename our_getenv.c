#include "shell.h"
/**
 * our_getenv - function gets the environment of a variabe
 * @var: variable name
 *
 *
 * Return: the environment of the variable if found, otherwise NULL
 *
 */

char *our_getenv(char *var)
{
	char *k, *val, *env, *temp;
	int n;

	for (n = 0; environ[n]; n++)
	{
		temp = _strdup(environ[n]);
		k = strtok(temp, "=");
		if (_strcmp(k, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
