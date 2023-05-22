
#include "shell.h"

char *get_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    nread = getline(&line, &bufsize, stdin);
    if (nread == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    return line;
}
