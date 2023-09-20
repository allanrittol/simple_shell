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
int _implement(char **cmd, char **argv, int index);
char *our_getenv(char *var);
char *path_handler(char *cmd);
void _perror(char *title, char *comd, int index);
char *_iota(int i);
void _reverse_string(char *stm, int span);
void builtin_handler(char **cmd, char **argv, int *stat, int index);
void exit_shell(char **cmd, int *stat);
void env_builtin(char **cmd, int *stat);
int check_builtin(char *cmd);

#endif
