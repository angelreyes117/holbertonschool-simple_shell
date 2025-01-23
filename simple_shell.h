/*
 * File: simple_shell.h
 * Author: Your Name
 * Description: Header file for the simple UNIX command line interpreter.
 */

#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern char **environ;
int simple_shell(void);

#endif /* SIMPLE_SHELL_H */

