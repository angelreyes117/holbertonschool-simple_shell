#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "

extern char **environ;  /* Declare environ as external */

void handle_error(char *command);
int simple_shell(void);

#endif /* SHELL_H */
