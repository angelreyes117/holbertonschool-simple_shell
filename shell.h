#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Function prototypes */
void display_prompt(void);
void process_command(char *line, char **env);
int execute_command(char **args, char **env);
int handle_builtin(char **args, char **env);
void print_env(char **env);

#endif /* SHELL_H */

