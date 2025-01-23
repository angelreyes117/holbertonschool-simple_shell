/*
 * File: simple_shell.c
 * Description: A simple UNIX command line interpreter that
 *              executes single-word commands using execve.
 */

#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: 0 on success, or an error code on failure
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}
		line[nread - 1] = '\0'; /* Remove newline character */
		if (line[0] == '\0')
			continue;

		argv[0] = line;
		argv[1] = NULL;

		if (execve(argv[0], argv, environ) == -1)
			perror(argv[0]);
	}

	return (0);
}
