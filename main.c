/*
 * File: main.c
 * Author: Your Name
 * Description: A simple shell program that waits for user input,
 *              parses commands, and executes them.
 */

#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, or an error code on failure
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}
		printf("Command: %s", line);
	}
	free(line);
	return (0);
}
