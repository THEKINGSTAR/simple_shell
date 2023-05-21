#include "shell.h"

int find_file(char *dir_name, char *file_name)
{
	int x;
	struct dirent *e;
	DIR *f;

	f = opendir(dir_name);
	if (f == NULL)
	{
		x = 0;
		perror("openning");
		return (x);
	}
	while ((e = readdir(f)) != NULL)
	{
		if (strcmp(e->d_name, file_name) == 0)
		{
			x = 1;
			break;
		}
	}
	closedir(f);
	return (x);
}
