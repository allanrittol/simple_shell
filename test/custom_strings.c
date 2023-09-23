#include "main.h"

/**
 * _strlen - function to get length of string
 * @str: string to be measured
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t l = 0;

	while (str[l] != '\0')
		l++;
	return (l);
}

/**
 * _strcmp - custom strcmp function
 * @str1: first string
 * @str2: second string
 *
 * Return: comparison of strings
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strcat - custom strcat function
 * @dest: destination string
 * @src: source string
 *
 * Return: original string
 */

char *_strcat(char *dest, const char *src)
{
	char o_dest = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (o_dest);
}




