#include "shell.h"

/**
 * execute_command - Executes the given command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	if (execve(command, argv, NULL) == -1)
	{
		perror("./hsh");
		exit(errno);
	}
}
