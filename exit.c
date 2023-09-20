#include "main.h"

/**
 * positive_num - function that checks if a string reps a positive integer
 * @stm: input string
 *
 * Return: 1 on success, 0 on failure
 */

int positive_num(char *stm)
{
	int j;

	if (!stm)
		return (0);
	for (j = 0; stm[j]; j++)
	{
		if (stm[j] < '0' || stm[j] > '9')
			return (0);
	}
	return (1);
}

/**
 * _atoi - function that converts a string into an integer
 * @stm: input string
 *
 * Return: integer
 */

int _atoi(char *stm)
{
	int j, numb = 0;

	for (j = 0; stm[j]; j++)
	{
		numb *= 10;
		numb += (stm[j] - '0');
	}
	return (numb);
}
