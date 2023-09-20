#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIMITER " \t\n"
extern char **environ;


int print_numbers(void);
char *read_input(void);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char **tokenizer(char *lineptr);
void freearray(char **array);
int _implement(char **cmd, char **argv);


#endif
