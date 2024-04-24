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
    int exit_num = -1;
    int exit_status = EXIT_SUCCESS;
    (void)argc;
    while (status_return && n_char != EOF)
      {
	input = NULL;
	status_return = isatty(STDIN_FILENO);
	if (status_return)
    {
      printf("Cisfun$ ");
    }
      if (read_input(&input, &input_size) == -1)
		{
			free(input);
			break;
		}
      if (input[0] == '\0')
		{
			free(input);
			continue;
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
      free(command);
      free_token_command(args);
      continue;
    }
  
        if (strcmp(args[0], "exit") == 0)
        {
                if (args[1])
                        exit_status = atoi(args[1]);
                else if (exit_num != -1)
                        exit_status = exit_num;
                free_token_command(args);
                free(input);
                exit(exit_status);
        }
        else if (strcmp(args[0], "env") == 0)
        {
                print_env();
                free_token_command(args);
                continue;
        }
  else
    {
 
          execute_command(argv, args, env);
    }
  
  free(command);
  free_token_command(args);	  
    }
    return (0);
}
