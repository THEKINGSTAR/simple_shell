#include "shell.h"

void free_grid(char **grid)
{
    if (grid == NULL)
    {
        return;
    }

    for (int i = 0; grid[i] != NULL; i++)
    {
        free(grid[i]);
    }

    free(grid);
}
