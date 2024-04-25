#include "shell.h"
/**
 * main - The main function for a simple shell program
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * @env: List of environment variables.
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *input = NULL, *command = NULL, **args = NULL, *line;
	size_t input_size = 0;
	int exit_num = -1, exit_status;
	(void)argc;
	signal(SIGINT, sigint_handler);
while (1)
{
if (isatty(STDIN_FILENO))
printf("Cisfun$ ");
if (read_input(&input, &input_size) == -1)
{
free(input);
break;
}
line = strtok(input, "\n");
while (line != NULL)
{
if (!check_spaces_tabs(line))
{
args = split_string(line, &command);
if (args == NULL)
{
line = strtok(NULL, "\n");
continue;
}
if (strcmp(args[0], "exit") == 0)
{
if (args[1])
exit_status = _atoi(args[1]);
else if (exit_num != -1)
exit_status = exit_num;
free_token_command(args);
free(input);
free(command);
exit(exit_status);
}
else if (strcmp(args[0], "env") == 0)
print_env();
else
execute_command(argv, args, env), free_token_command(args), free(command);
}
line = strtok(NULL, "\n");
}
free(input), input = NULL, input_size = 0;
}
return (0);
}
