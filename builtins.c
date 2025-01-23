#include "shell.h"

/**
 * handle_builtin - Handles built-in commands
 * @args: Command and arguments
 * @env: Environment variables
 *
 * Return: 1 if a built-in command is executed, 0 otherwise
 */
int handle_builtin(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0)
		exit(0);
	else if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}
	return (0);
}

/**
 * print_env - Prints environment variables
 * @env: Environment variables
 */
void print_env(char **env)
{
	for (int i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}

