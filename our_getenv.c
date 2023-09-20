#include "shell.h"

char *_getenv(char *var)
{
	char *k, *val, *env, *k;
	int n;

	for(n = 0; environ[n])
	{
		tmp = _strdup(environ[n]);
		k = strtok(tmp,"=");
		if (_strcmp(k, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
