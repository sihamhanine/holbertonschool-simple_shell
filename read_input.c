#include "shell.h"

/**
 * read_input - Read user input from stdin
 * @input: A pointer to the input string
 * @buf_size: A pointer to the buffer size
 *
 * Return: The number of characters read, or -1 on error.
 */
ssize_t read_input(char **input, size_t *buf_size)
{
	ssize_t n_char;

	n_char = getline(input, buf_size, stdin);
	if (n_char == -1)
	{
		if (!isatty(STDIN_FILENO))
			return (-1);
		free(*input);
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if ((*input)[n_char - 1] == '\n')
		(*input)[n_char - 1] = '\0';

	return (n_char);
}
