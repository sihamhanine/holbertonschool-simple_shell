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
  char *input = NULL, **args = NULL, *command = NULL;
  size_t input_size = 0;
  ssize_t n_char;
while (1)
{
  if (isatty(STDIN_FILENO))
    {
      printf("cisfun$ ");
    }
  n_char = getline(&input, &input_size, stdin);
  if (n_char == -1)
    {
      perror("error reading input");
      free(input);
      exit(EXIT_FAILURE);
    }
  if (check_spaces_tabs(input))
    {
      free(input);
      continue;
    }
  args = split_string(input, &command);
  if (args == NULL)
    {
      perror("error to split input");
      free(input);
      continue;
    }
  if (strcmp(args[0], "exit") == 0)
    {
      free_token_command(args);
      free(command);
      free(input);
      exit(EXIT_SUCCESS);
    }
  else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		free_token_command(args);
		free(command);
		continue;
	}
  else {
	  execute_command(command);
  }
  
  free(command);
  free_token_command(args);
 }
 return (0);
}
  
