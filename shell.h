#ifndef SHELL_H
#define SHELL_H
void read_input(char **av, char **env);
void print_env(void);
char *_strcpy(char *dest, char *src);
int _strlen(const char *str);
char **split_string(char *input);
void free_token_command(char **token);

extern char **environ;
#endif
