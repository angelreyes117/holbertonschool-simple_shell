#include "shell.h"

/**
 * prompt - Displays the shell prompt and handles user input.
 */
void prompt(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int is_interactive = isatty(STDIN_FILENO); /* Check if the shell is in interactive mode */

	while (1)
	{
		if (is_interactive) /* Only show the prompt in interactive mode */
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Handle EOF (Ctrl+D) */
		{
			free(line);
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		/* Remove the newline character from input */
		line[nread - 1] = '\0';

		if (strlen(line) == 0) /* Handle empty command */
			continue;

		pid = fork(); /* Create a child process */
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0) /* Child process */
		{
			execute_command(line);
		}
		else /* Parent process */
		{
			wait(NULL); /* Wait for the child process to finish */
		}
	}
}
