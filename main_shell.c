#include "shell.h"
#include <stdio.h>

/**
 * main - The main function for a simple shell program
 *
 * Description: this program create a basic shell
 * accepting and executing command entered by the user
 * @ac: number of arguments passed in input
 * @av: list of string entred
 * @env: variable environment of string
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
while (ac == 1)
{
read_input(av, env);
}
return (0);
}
