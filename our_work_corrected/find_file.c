
#include "shell.h"

int find_file(const char *dir_name, const char *file_name)
{
    DIR *dir;
    struct dirent *entry;
    int found = 0;

    dir = opendir(dir_name);
    if (dir == NULL)
    {
        perror("opendir");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, file_name) == 0)
        {
            found = 1;
            break;
        }
    }

    closedir(dir);

    return found;
}


