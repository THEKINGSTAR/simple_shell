#include "shell.h"

/**
 * handle_path - handle the path
 *
 * Return: array of string contain all the PATH
 */
char **handle_path()
{
	char *path, *token;
	char **dir;
	int size, position;

	path = getenv("PATH");
	size = 64;
	dir = malloc(sizeof(char *) * size);
	if (dir == NULL)
	{
		perror("memory allocating");
		exit(EXIT_FAILURE);
	}
	position = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		dir[position] = token;
		position++;
		if (position >= size)
		{
			size += 1024;
			dir = realloc(dir, size);
			if (dir == NULL)
			{
				perror("memory allocating");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, ":");
	}
	dir[position] = NULL;
	return (dir);
}
