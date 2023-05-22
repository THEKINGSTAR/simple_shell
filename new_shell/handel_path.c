
#include "shell.h"

char **handle_path(void)
{
    char *path = getenv("PATH");
    char **directories = NULL;
    char *token;
    const char *delimiter = ":";

    int count = 0;

    if (path == NULL)
    {
        perror("getenv");
        exit(EXIT_FAILURE);
    }

    token = strtok(path, delimiter);
    while (token != NULL)
    {
        directories = realloc(directories, (count + 1) * sizeof(char *));
        if (directories == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        directories[count] = strdup(token);
        if (directories[count] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        count++;
        token = strtok(NULL, delimiter);
    }

    directories = realloc(directories, (count + 1) * sizeof(char *));
    if (directories == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    directories[count] = NULL;

    return directories;
}