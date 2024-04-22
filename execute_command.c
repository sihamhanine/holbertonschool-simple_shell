#include "shell.h"
/**
 * execute_command - Function to execute the command if
 * it exist in folder
 * @command: the command to execute
 * @args: the arguments of command
 */
int execute_command(char *command, char **args)
{
  int status = -1;
  pid_t pid;
  void(command);    
    if (!find_command(args))
    {
      fprintf(stderr, "%s: Command not found\n", args[0]);
      free_token_command(args);
      return (0);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid == 0)
    {
        execve(args[0], args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
        free_token_command(args);;
        return status;
    }
}
