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
	char **cmd = NULL;
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
	cmd = malloc(sizeof(char *) * (count + 1));

	if (!cmd)
	{
		free(lineptr), lineptr = NULL;
		return (NULL);
	}
	token = strtok(lineptr, DELIMITER);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIMITER);
		i++;
	}

	free(lineptr), lineptr = NULL;
	cmd[i] = NULL;
	return (cmd);
}

