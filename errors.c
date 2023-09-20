#include "main.h"
/**
 * _perror - function that prints the error message
 * @title: pointer to string representing error message
 * @comd: pointer to string representing command
 * @index: integer value
 *
 * Return: nothing
 */

void _perror(char *title, char *comd, int index)
{
	char *i, message[] = ":not found\n";

	i = _iota(index);

	write(STDERR_FILENO, title, _strlen(title));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, comd, _strlen(comd));
	write(STDERR_FILENO, message, _strlen(message));

	free(i);
}

/**
 * _iota - function that converts an integer into a string
 * @i: integer to be converted
 *
 *Return: duplicated string
 */

char *_iota(int i)
{
	char buff[20];
	int j = 0;

	if (i == 0)
		buff[j++] = '0';
	else
	{
		while (i > 0)
		{
			buff[j++] = (i % 10) + '0';
			i /= 10;
		}
	}
	buff[j] = '\0';
	_reverse_string(buff, j);
	return (_strdup(buff));
}

/**
 * _reverse_string - function that reverses a string in-place
 * @stm: pointer to the string to be reversed
 * @span: length of the string to be reversed
 *
 * Return: nothing
 */
void _reverse_string(char *stm, int span)
{
	char temp;
	int init = 0, term = span - 1;

	while (init < term)
	{
		temp = stm[init];
		stm[init] = stm[term];
		stm[term] = temp;
		init++;
		term--;
	}
}
