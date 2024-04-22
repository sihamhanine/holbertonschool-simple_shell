#include "shell.h"
/**
 *
 */
char *find_command(char *args)
{
    char*dir;
    int i = 0;
    char path_search[4096];
        const char *path[] = {"/bin", "/usr/bin", NULL};
        while(path[i] != NULL)
        {
                sprintf(path_search, path[i], args);
                    if (access(path_search, X_OK) == 0)
                    {
                        return strdup(path_search);
                    }
                    i++;
        }
    return NULL;
}
void execute_command(char *command) {
    int status = -1;
    pid_t pid;
    char *cmd = find_command(command);
    if (cmd) {
        char *argv[] = {cmd, NULL};
        pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            execve(argv[0], argv, environ);
            perror("execve");
            free(cmd);
            free_token_command(argv);
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
            free(cmd);
            free_token_command(argv);
        }
    } else {
        fprintf(stderr, "Command not found\n");
    }
}
