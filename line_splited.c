#include "shell.h"

char **split(char *line)
{
    char **tokens = NULL;
    char *token;
    const char *delimiters = " \t\r\n\a"; /* Whitespace characters */

    int count = 0;

    token = strtok(line, delimiters);
    while (token != NULL)
    {
        tokens = realloc(tokens, (count + 1) * sizeof(char *));
        if (tokens == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        tokens[count] = strdup(token);
        if (tokens[count] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        count++;
        token = strtok(NULL, delimiters);
    }

    tokens = realloc(tokens, (count + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    tokens[count] = NULL;

    return tokens;
}
