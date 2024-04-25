#include "shell.h"
/**
 * sigint_handler - Custom signal handler for SIGINT (Ctrl+C)
 */
void sigint_handler(int signum) {
    (void)signum; 
    write(STDOUT_FILENO, "\n$ ", 3); 
}
