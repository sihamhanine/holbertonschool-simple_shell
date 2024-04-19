#include "shell.h"
/**
 * _strcpy - Function that copies a string from src
 * to dest
 * @dest: string to copy to
 * @src: string to copy from
 *
 * Return: pointer to the dest string
 */
char *_strcpy(char *dest, char *src)
{
  int i;
  for (i = 0; src[i] != '\0'; i++)
    {
      dest[i] = src[i];
    }
  dest[i] = '\0';
  return (dest);
}

/**
 * _strlen - Function that calculate input length
 * excluding \0
 * @str: the input string
 *
 * Return: lenght of the string
 */
int _strlen(const char *str)
{
  int i;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
