#include "shell.h"

/**
 * get_line - read line from user
 *
 * Return: line that user entered
 */
char *get_line()
{
	char *line;
	size_t nread;
	int nsize, c, i;

	nsize = 1024;
	i = 0;
	line = malloc(sizeof(char) * nsize);
	if (line == NULL)
	{
		perror("memory allocate");
		exit(EXIT_FAILURE);
	}
	if (getline(&line, &nread, stdin) != -1)
	{
		while (1)
		{
			c = line[i];
			if (c == EOF || c == '\n')
			{
				line[i] = '\0';
				return (line);
			}
			i++;
			if (i >= nsize)
			{
				nsize += 1024;
				line = realloc(line, nsize);
				if (line == NULL)
				{
					perror("memory allocate");
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
