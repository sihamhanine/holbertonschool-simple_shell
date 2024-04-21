#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * main - The main function for a simple shell program
 *
 * Description: this program create a basic shell
 * accepting and executing command entered by the user
 * 
 * Return: Always 0
 */
int main(void)
{
  char *input = NULL, **args = NULL;
  size_t input_size = 0;
  ssize_t n_char;
  int status;
  pid_t child_pid;
while (1)
{
  if (isatty(STDIN_FILENO))
    {
      printf("cisfun$ ");
    }
  n_char = getline(&input, &input_size, stdin);
  if (n_char == -1)
    {
      free(input);
      exit(EXIT_FAILURE);
    }
  if (check_spaces_tabs(input))
    {
      free(input);
      exit(EXIT_FAILURE);
    }
  args = split_string(input);
  if (strcmp(args[0], "exit") == 0)
    {
      free_token_command(args);
      free(input);
      exit(0);
    }
  else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		free_token_command(args);
		exit(EXIT_FAILURE);
	}
child_pid = fork();
if (child_pid == -1)
{
free(input);
exit(EXIT_FAILURE);
}
if (child_pid == 0)
{
args[0] = input;
if (execve(args[0], args, NULL) == -1)
{
printf("%s: No such file or directory\n", args[0]);
exit(EXIT_FAILURE);
}
}
else
wait(&status);  
 }
 return (0);
}
