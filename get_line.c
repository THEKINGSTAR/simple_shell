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
	int c, i;

	size = 0;

	if(getline(&line, &size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	if (_strcmp(line, "\n") == 0)
		return (line);
	while (1)
	{
		c = line[i];
		if (c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (line);
}
