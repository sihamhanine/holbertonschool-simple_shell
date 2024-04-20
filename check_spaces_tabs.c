#include "shell.h"

/**
 * check_spaces_tabs - Function that check if a string contains
 * only spaces and tabs
 * @input: The string to check
 *
 * Description:
 * This function checks if the input string contains only spaces and tabs. If
 * the string contains any character other than space or tab, it returns 0. If
 * the string consists only of spaces and tabs, it returns 1.
 *
 * Return: 1 if the string contains only spaces and tabs, 0 otherwise.
 */
int check_spaces_tabs(char *input)
{
	while (*input != NULL)
	{
		if (*input != ' ' && *input != '\t')
			return (0);
		input++;
	}
	return (1);
}
