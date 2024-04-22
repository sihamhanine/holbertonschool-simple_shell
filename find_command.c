#include "shell.h"
/**
 *
 */
char *find_command(char *command)
{
  char *path = getenv("PATH");
  char *token;
  char *cmd_full;
  struct stat st;
  token = strtok(path, ":");
  while (token != NULL)
    {
      cmd_full = malloc(strlen(token) + strlen(command) + 2);
      strcpy(cmd_full, token);
      strcat(cmd_full, "/");
      strcat(cmd_full, command);
      if (stat(cmd_full, &st) == 0)
	{
	  return (cmd_full);
	}
	  token = strtok(NULL, ":");
    }
  free(cmd_full);
  return (NULL);
    }
