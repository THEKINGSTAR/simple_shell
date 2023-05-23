#include "shell.h"

char *split_arg(char *line)
{
    int bufsize = 64;
    int position = 0;
    char *token;
    char **tokens = malloc(bufsize * sizeof(char*));
    if (tokens == NULL)
    {
        fprintf(stderr, "error in memory allocation");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, "/");
    while (token != NULL)
    {
        tokens[position] = strdup(token);
        position++;

        if (position >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (tokens == NULL)
            {
                fprintf(stderr, "error in memory allocation");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, "/");
    }
    return tokens[position - 1];
    
}
