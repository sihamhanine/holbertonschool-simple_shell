#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * 
 */
void mode_interactif(char **argv, char **env)
{

  char *input = NULL, **args = NULL, *command = NULL;
  size_t input_size = 0;
  ssize_t n_char;
while (1)
{
      printf("cisfun$ ");
  n_char = getline(&input, &input_size, stdin);
        if (n_char == EOF)
        {
                if (isatty(STDIN_FILENO))
                {
                        write(STDOUT_FILENO, "\n", 1);
                }
                perror("error reading input");
                free(input);
                exit(0);
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
          execute_command(argv, args, env);
  }

  free(command);
  free_token_command(args);
 }
}
