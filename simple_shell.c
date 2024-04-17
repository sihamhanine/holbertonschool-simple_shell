#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define PROMPT "#cisfun$ "

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;
    char *argv[] = {"/bin/ls", NULL }; 
    while (1) {
        printf(PROMPT);

        read = getline(&line, &len, stdin);
        if (read == -1) {
            printf("\n"); 
            break;
        }

        
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }

       
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else
	  if (pid == 0)
	    { 
	      argv[0] = line;
            if (execve(line, argv, NULL) == -1)
	      {
                fprintf(stderr, "%s: No such file or directory\n", line);
                exit(EXIT_FAILURE);
            }
        } else
	    {
            wait(&status);
        }
    }

    free(line);
    return EXIT_SUCCESS;
}
