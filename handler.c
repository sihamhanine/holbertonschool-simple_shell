#include "shell.h"
/**
 * sigint_handler - Custom signal handler for
 * SIGINT (Ctrl+C)
 * @signum: the number of signal
 */
void sigint_handler(int signum)
{
(void)signum;
write(STDOUT_FILENO, "\n$ ", 3);
}
