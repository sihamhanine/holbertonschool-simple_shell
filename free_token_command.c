#include "shell.h"
/**
 * free_token_command - Function that free the memory
 * allocated dynamicly
 * @token: the array of token to free
 *
 */
void free_token_command(char **token)
{
  int i = 0;
  while (token[i] != NULL)
    {
      free(token[i]);
      i++;
    }
  free(token);
}
