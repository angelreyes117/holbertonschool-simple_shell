#include "shell.h"
#include <ctype.h>

/**
 * trim_spaces - Remove leading, trailing, and redundant spaces
 * @str: Input string
 * Return: Pointer to the trimmed string
 */
char *trim_spaces(char *str)
{
	char *end;
	size_t i = 0, j = 0;

	/* Skip leading spaces */
	while (isspace(str[i]))
		i++;

	/* Copy the trimmed content */
	while (str[i])
	{
		if (!isspace(str[i]) || (j > 0 && !isspace(str[j - 1])))
			str[j++] = str[i];
		i++;
	}

	/* Remove trailing spaces */
	if (j > 0 && isspace(str[j - 1]))
		j--;

	str[j] = '\0';
	return (str);
}

/**
 * main - Entry point of the shell
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[100];
	int i;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		/* Trim spaces and check for empty command */
		trim_spaces(line);
		if (line[0] == '\0')
			continue;

		/* Tokenize input */
		i = 0;
		argv[i] = strtok(line, " ");
		while (argv[i] && i < 99)
			argv[++i] = strtok(NULL, " ");
		argv[i] = NULL;

		/* Execute the command */
		if (argv[0] && execvp(argv[0], argv) == -1)
			perror(argv[0]);
	}

	free(line);
	return (0);
}
