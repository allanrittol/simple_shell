<<<<<<< HEAD
#include "main.h"
=======
#include "shell.h"

>>>>>>> 8f649e5da1d57fa4aa9f618392cfb95843a61479
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

	for (n = 0; envr[n]; n++)
	{
		temp = _strdup(envr[n]);
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
