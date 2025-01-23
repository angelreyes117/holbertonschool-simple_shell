#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc;
	(void)argv;

	while (1)
	{
		display_prompt();
		nread = getline(&line, &len, stdin);

		if (nread == -1) /* Handle EOF or Ctrl+D */
			break;

		process_command(line, env);
	}

	free(line);
	return (0);
}

