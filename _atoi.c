#include "shell.h"
/**
 * _atoi - converts a string into an integer
 *@str: pointer to a string
 *Return: the integer
 */
int _atoi(char *str)
{
	int i, nbre, signe = 1;

	i = 0;
	nbre = 0;
	while (!((str[i] >= '0') && (str[i] <= '9')) && str[i] != '\0')
	{
		if (str[i] == '-')
		{
			signe = signe * (-1);
		}
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbre = (nbre * 10) + (str[i] - '0');
		i++;
	}
	return (nbre * signe);
}
