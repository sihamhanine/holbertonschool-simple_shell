#include "shell.h"
/**
 *
 */

void mode_no_interactif(char **argv, char **env)
{
   char *input = NULL, **args = NULL, *command = NULL;
    size_t input_size = 0;
    ssize_t n_char;
   
  if (!isatty(STDIN_FILENO))
    {
      n_char = getline(&input, &input_size, stdin);
      if (n_char == -1)
	{
	  perror("erreur lors de lecteur de l'entree\n");
	  exit(EXIT_FAILURE);
	}
      if (check_spaces_tabs(input))
    {
      free(input);
      
    }
  args = split_string(input, &command);
  if (args == NULL)
    {
      perror("error to split input");
      free(input);
      
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
                
        }
  else {
          execute_command(argv, args, env);
  }

  free(command);
  free_token_command(args);	  
    }
      
}
