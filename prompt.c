#include "shell.h"
#include <ctype.h> /* For isspace */

/**
 * trim_spaces - Trims leading and trailing spaces from a string.
 * @str: Input string.
 * Return: Pointer to the trimmed string.
 */
char *trim_spaces(char *str)
{
	char *end;

	/* Trim leading spaces */
	while (isspace((unsigned char)*str))
		str++;

	if (*str == 0) /* All spaces */
		return str;

	/* Trim trailing spaces */
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end))
		end--;

	/* Write the null terminator */
	*(end + 1) = '\0';

	return str;
}

/**
 * prompt - Displays the shell prompt and handles user input.
 */
void prompt(void)
{
	char *line = NULL, *trimmed_line;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			if (is_interactive)
				write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		/* Trim spaces and handle empty input */
		trimmed_line = trim_spaces(line);
		if (strlen(trimmed_line) == 0)
			continue;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0) /* Child process */
		{
			execute_command(trimmed_line);
		}
		else /* Parent process */
		{
			wait(NULL);
		}
	}
}
