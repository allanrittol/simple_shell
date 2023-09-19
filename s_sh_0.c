#include "main.h"
/**
 * print_numbers - entry point of the function that prints odd/even numbers
 *
 * Return: (0) if successful
 */
int print_numbers(void)
{
	int i;
	pid_t ppid;

	ppid = getppid();

	for (i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			printf("Even: %d\n", i);
			printf("pp_ID is %d\n", ppid);
		}
		else
		{
			printf("Odd: %d\n", i);
			printf("pp_ID is %d\n", ppid);
		}
	}
	return (0);
}
