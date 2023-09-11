#include <stdio.h>
/**
 * main - entry point of the function that prints odd/even numbers
 *
 * Return: (0) if successful
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("Even: %d\n", i);
		}
		else
		{
			printf("Odd: %d\n", i);
		}
	}
	return (0);
}
