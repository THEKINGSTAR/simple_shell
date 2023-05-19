#include "shell.h"

int main(void)
{
	char *line = "This is a test line";
    char **x = split_line(line);

    for (int i = 0; x[i] != NULL; i++)
    {
        printf("%s\n", x[i]);
    }

    for (int i = 0; x[i] != NULL; i++)
    {
        free(x[i]);
    }
    free(x);

    return 0;
}
