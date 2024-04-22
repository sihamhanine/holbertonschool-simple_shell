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
            free_token_command(args);
            free(*command);
            exit(EXIT_FAILURE);
        }

        args[i] = (char *)malloc(_strlen(token) + 1);
        if (args[i] == NULL)
        {
            perror("allocation non reussi");
            free_token_command(args);
            free(*command);
            exit(EXIT_FAILURE);
        }
        _strcpy(args[i], token);
        token = strtok(NULL, delim);
        i++;
    }

    args[i] = NULL;
    if (*command != NULL) {
        free(*command);
    }
    return (args);
}
