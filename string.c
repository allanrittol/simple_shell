#include "main.h"

/**
 * _strlen - function that returns length of string
 * @str: string whose length to be checked
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int len = 0;

	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

/**
 * _strcpy - function that copies a string
 * @dest: string destination
 * @src: string source
 *
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcmp - function that compares strings
 * @str1: first string
 * @str2: second string
 *
 * Return: -ve if str1 < str2, +ve if str1 > str2 and 0 if str1 == str2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strcat - function that concatenates strings
 * @dest: buffer destination
 * @src: buffer source
 *
 * Return: pointer to buffer destination
 */

char *_strcat(char *dest, char *src)
{
	int i, destlen = 0, srclen = 0;

	for (i = 0; dest[i] != '\0'; i++)
		destlen++;
	for (i = 0; src[i] != '\0'; i++)
		srclen++;
	for (i = 0; i <= srclen; i++)
		dest[destlen + i] = src[i];

	return (dest);
}

/**
 * _strdup - function that duplicates a string
 * @str: string to be duplicated
 *
 * Return: pointer to duplicated string
 */

char *_strdup(const char *str)
{
	int n, len = 0;
	char *p;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (n = 0; n <= len; n++)
		p[n] = str[n];
	return (p);
}


