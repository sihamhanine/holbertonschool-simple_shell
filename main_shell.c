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
int main(int argc, char **argv, char **env)
{
  (void)argc;
  if (isatty(STDIN_FILENO))
    {
  mode_interactif(argv, env);
    }
  else
    {
    mode_no_interactif(argv, env);
    }
  return (0);
}
