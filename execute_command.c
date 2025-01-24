#include "shell.h"

/**
 * execute_command - Executes a command entered by the user.
 * @cmd: The command to execute.
 */
void execute_command(char *cmd)
{
	char *args[1024];
	char *token;
	int i = 0;

	/* Tokenize the input string into arguments */
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	/* Execute the command */
	if (execvp(args[0], args) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}
