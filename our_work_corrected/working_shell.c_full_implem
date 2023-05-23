#include "shell.h"

int main(void)
{
    char *line;
    char **line_splited;
    char **path;

    while (1)
    {
        printf("($) ");
        line = get_line();
        line_splited = split(line);
        path = handle_path();

        execute(line_splited, path);

        free(line);
        free_grid(line_splited);
        free_grid(path);
    }

    return 0;
}


