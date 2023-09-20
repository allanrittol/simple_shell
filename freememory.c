#include "main.h"

/**
 * freearray - function that performs memory cleanup for dynamically
 * allocated strings ensuring no memory leaks
 *
 * @array: array of strings to be freed
 *
 * Return: nothing
 */

void freearray(char **array)
{
	int s;

	if (!array)
		return;

	for (s = 0; array[s]; s++)
	{
		free(array[s]);
		array[s] = NULL;
	}
	free(array);
	array = NULL;
}
