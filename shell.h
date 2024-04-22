#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h> 
void read_input(char **av, char **env);
void print_env(void);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
char **split_string(char *input, char **command);
void free_token_command(char **token);
int check_spaces_tabs(char *input);
void execute_command(char *command);
char *find_command(char *command);
extern char **environ;
#endif
