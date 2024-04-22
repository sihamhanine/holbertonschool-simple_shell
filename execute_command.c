#include "shell.h"
/**
 * execute_command - Function to execute the command if
 * it exist in folder
 * @command: the command to execute
 * @args: the arguments of command
 */
int execute_command(char *command, char **args)
{
    int status;
    pid_t pid;
    char *full_path = find_command(command);

    if (full_path == NULL)
    {
        fprintf(stderr, "%s: Command not found\n", command);
        return -1;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(full_path);
        return -1;
    }
    else if (pid == 0)
    {
        execve(full_path, args, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
        free(full_path);
        return status;
    }
}
