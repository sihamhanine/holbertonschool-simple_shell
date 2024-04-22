#include "shell.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * split_string - Function that split an input string into
 * an array of arguments
 * @input: The user input string to split
 *
 * Return: An array of pointers to the splited arguments,
 * or NULL on failure.
 */
char **split_string(char *input, char **command)
{
    char **args = NULL;
    char *delim = " \n\t";
    char *token;
    int i = 0;

    token = strtok(input, delim);
    if (token != NULL) {
        *command = strdup(token);
        if (*command == NULL) {
            perror("allocation non reussi");
            exit(EXIT_FAILURE);
        }
    }

    while (token != NULL)
    {
        args = (char **)realloc(args, (i + 2) * sizeof(char *));
        if (args == NULL)
        {
            perror("allocation non reussi");
            exit(EXIT_FAILURE);
        }

        args[i] = strdup(token);
        if (args[i] == NULL)
        {
            perror("allocation non reussi");
            exit(EXIT_FAILURE);
        }
        
        token = strtok(NULL, delim);
        i++;
    }

    args[i] = NULL;
    return (args);
}
