#include "main.h"

/**
 * our_getenv - function gets the environment of a variable
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

/**
 * print_error - function to print error message to STDERR
 * @message: error message to be printed.
 */
void print_error(const char *message)
{
	if (write(STDERR_FILENO, message, strlen(message)) == -1)
		perror("wrie");
}

/*
 * constr_env_var - function to construct an env variable string
 * @name: env var name
 * @value: value to assign to new env variable
 *
 * Return: new env variable
 */

char *constr_env_var(const char *name, const char *value)
{
	char *new_entry;

	new_entry = malloc(strlen(name) + strlen(value) + 2);
	if (new_entry == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	strcpy(new_entry, name);
	strcat(new_entry, "=");
	strcat(new_entry, value);

	return (new_entry);
}

/**
 * set_env_var - function to set/modify environment variable
 * @name: name of the environment variable to set/modify
 * @value: value to assign to env variable
 * @overwrite: if set to 1, overwrite the variable if it already exists,
 *		if set to 0, do not overwrite an existing variable.
 * Return: 0 on success, -1 on failure.
 */

int set_env_var(const char *name, const char *value, int overwrite)
{
	int i = 0;
	char *entry = environ[i], *new_entry;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strcmp(entry, name) == 0 && entry[strlen(name)] == '=')
		{
			if (!overwrite)
			{
				print_error("Variable exists, and overwrite is not allowed\n");
				return (0);
			}
			else
			{
				new_entry = constr_env_var(name, value);
				if (new_entry == NULL)
					return (-1);
				free(environ[i]);
				environ[i] = new_entry;
				print_error("Overwriting environment variable\n");
				if (write(STDERR_FILENO, new_entry, strlen(new_entry)) == -1)
					perror("write");
				return (0);
			}
		}
	}
	return (add_new_var(name, value));
}

/**
 * add_new_var - function that adds a new env variable
 * @name: name of new env variable
 * @value: value to assign to new variable
 *
 * Return: 0 on success, -1 on failure.
 */

int add_new_var(const char *name, const char *value)
{
	int i;
	char **new_var, *new_entry;

	new_var = malloc(sizeof(char *) * (environ_size() + 2));
	if (new_var == NULL)
	{
		perror("malloc");
		return (-1);
	}
	while (environ[i] != NULL)
	{
		new_var[i] = environ[i];
		i++;
	}
	new_entry = constr_env_var(name, value);
	if (new_entry == NULL)
		return (-1);

	new_var[i] = new_entry;
	new_var[i + 1] = NULL;
	environ = new_var;

	print_error("Setting new environment variable\n");

	if (write(STDERR_FILENO, new_entry, strlen(new_entry)) == -1)
		perror("write");

	return (0);
}

