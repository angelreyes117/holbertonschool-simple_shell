#include "shell.h"

/**
 * execute_command - Executes a command
 * @args: Parsed command and arguments
 * @env: Environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		wait(&status);
	else
		perror("fork");

	return (0);
}

