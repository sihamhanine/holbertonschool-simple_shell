#include "shell.h"
/**
 * main - The main function for a simple shell program
 *
 * Description: this program create a basic shell
 * accepting and executing command entered by the user
 * 
 * Return: Always 0
 */

int main(int argc, char **argv, char **env)
{
   char *input = NULL, **args = NULL, *command = NULL;
    size_t input_size = 0;
    ssize_t n_char = 0;
    int status_return = 1;
    (void)argc;
    while (status_return && n_char != EOF)
      {
	status_return = isatty(STDIN_FILENO);
	if (status_return)
    {
      printf("Cisfun$ ");
    }
      n_char = getline(&input, &input_size, stdin);
      if (n_char == -1)
	{
	  perror("erreur lors de lecteur de l'entree\n");
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
          execute_command(argv, args, env);
  }

  free(command);
  free_token_command(args);	  
    }
    return (0);
}
