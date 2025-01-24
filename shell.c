#include "shell.h"

extern char **environ;  /* Declare environ as external */

void handle_error(char *command)
{
    fprintf(stderr, "./simple_shell: 1: %s: not found\n", command);
}

int simple_shell(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *argv[2];
    pid_t child_pid;
    int status;

    while (1)
    {
        printf(PROMPT);
        fflush(stdout);

        read = getline(&line, &len, stdin);
        if (read == -1)  /* Handle EOF (Ctrl+D) */
        {
            if (feof(stdin))
            {
                printf("\n");
                free(line);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("getline");
                continue;
            }
        }

        /* Remove newline from command */
        line[strcspn(line, "\n")] = 0;

        /* Set up argument list for execve */
        argv[0] = line;
        argv[1] = NULL;

        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            continue;
        }
        if (child_pid == 0)
        {
            /* Child process */
            if (execve(line, argv, environ) == -1)
            {
                handle_error(line);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Parent process */
            wait(&status);
        }
    }

    free(line);
    return 0;
}

int main(void)
{
    return simple_shell();
}
