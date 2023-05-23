#include "shell.h"

void execute(char **line_splited, char **path)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        // Child process

        int i, found = 0;
        char *full_path = NULL;

        // Check if the command contains a path separator '/'
        if (strchr(line_splited[0], '/') != NULL)
        {
            if (access(line_splited[0], X_OK) == 0)
            {
                execv(line_splited[0], line_splited);
                perror("execv");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Search for the executable in the directories from PATH
            for (i = 0; path[i] != NULL; i++)
            {
                full_path = malloc(strlen(path[i]) + strlen(line_splited[0]) + 2); // +2 for '/' and null terminator
                if (full_path == NULL)
                {
                    perror("malloc");
                    exit(EXIT_FAILURE);
                }

                strcpy(full_path, path[i]);
                strcat(full_path, "/");
                strcat(full_path, line_splited[0]);

                if (access(full_path, X_OK) == 0)
                {
                    found = 1;
                    break;
                }

                free(full_path);
                full_path = NULL;
            }

            if (found)
            {
                execv(full_path, line_splited);
                perror("execv");
                exit(EXIT_FAILURE);
            }
        }

        // Command not found
        fprintf(stderr, "Command not found: %s\n", line_splited[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        waitpid(pid, &status, 0);
    }
}
