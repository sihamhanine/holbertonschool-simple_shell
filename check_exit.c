#include "shell.h"

/**
 * check_exit - check of exit shell commands
 * @args: An array of command arguments
 * @input: The user input string
 * @exit_num: The exit status to set on exit
 *
 * Return: 1 if the command is a exit, 0 otherwise.
 */
int check_exit(char **args, char *input, int exit_num)
{
	int exit_status = EXIT_SUCCESS;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			exit_status = _atoi(args[1]);
		else if (exit_num != -1)
			exit_status = exit_num;
		free_token_command(args);
		free(input);
		exit(exit_status);
		return (1);
	}
	return (0);
}
