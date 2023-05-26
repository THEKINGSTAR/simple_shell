#include "shell.h"

/**
 * get_line - take line from user
 *
 * Return: string
 */
char *get_line(void)
{
	char *line = NULL;
	size_t size;
	int i, c;

	size = 0;

	if(getline(&line, &size, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
	}
	return (line);

}
