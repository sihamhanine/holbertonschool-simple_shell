#include "shell.h"
#include <stdio.h>

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
  if (input[n_char - 1] == '\n')
    input[n_char - 1] == '\0';
  if (check_spaces_tabs(input))
    {
      free(input);
      exit(EXIT_FAILURE);
    }
 }
 return (0);
}
