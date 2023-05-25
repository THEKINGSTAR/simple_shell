#include "shell.h"

/**
 * find_file - find file in whitch directory
 * @fn: first pramter
 * @p: all pathes
 *
 * Return: the path
 */
char *find_file(char *fn, char **p)
{
	int i;
	int flag = 0;
	char *dir_path = NULL;
	struct dirent *e = NULL;
	DIR *dir = NULL;
	
	for(i = 0; p[i] != NULL; i++)
	{
		dir = opendir(p[i]);
		if (dir == NULL)
		{
			return (NULL);
		}
		while ((e = readdir(dir)) != NULL)
		{
			if (e->d_type == DT_REG && strcmp(e->d_name, fn) == 0)
			{
				dir_path = malloc(strlen(p[i]) + strlen(fn) + 2);
				if (dir_path == NULL)
				{
					closedir(dir);
					return (NULL);
				}
				strcpy(dir_path, p[i]);
				strcat(dir_path, "/");
				strcat(dir_path, fn);
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	if (p[i] == NULL)
	{
		free(e);
		closedir(dir);
		free(dir);
		return ("0");
	}
	closedir(dir);
	return (dir_path);
}
