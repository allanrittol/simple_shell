#include "main.h"

/**
 * tokenizer - function that splits a string into tokens based on a delimiter
 * @lineptr: input string
 *
 * Return: array of tokenized strings
 */

char **tokenizer(char *lineptr)
{
	char *token = NULL, *tmp;
	char **command = NULL;
	int count = 0, i = 0;

	if (!lineptr)
		return (NULL);
	tmp = _strdup(lineptr);
	token = strtok(tmp, DELIMITER);
	if (token == NULL)
	{
		free(lineptr), lineptr = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIMITER);
	}
	free(tmp);
	command = malloc(sizeof(char *) * (count + 1));

	if (!command)
	{
		free(lineptr), lineptr = NULL;
		return (NULL);
	}
	token = strtok(lineptr, DELIMITER);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}

	free(lineptr), lineptr = NULL;
	command[i] = NULL;
	return (command);
}

