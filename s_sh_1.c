#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * parse_input - function that parses the user input into a command
 * @input: user input text command
 * @command: pointer to pointer
 *
 * Return: (0) when successful
 */
int parse_input(char *input, char **command)
{
	char *token = str_tokn(input, "\t\n");

	if (token != NULL)
	{
		*command = token;
		return (1);
	}
	return (0);
}
/**
 * execute_command - function that executes a command
 * @command: a pointer
 *
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		excelp(command, command, NULL);
		perror(command);
		exit(1);
	}
	else
	{
		perror("fork");
	}
}
