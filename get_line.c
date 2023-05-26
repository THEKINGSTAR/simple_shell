#include "shell.h"

/**
* get_line - take line from user
*
* Return: string
*/
char *read_line(void)
{
	char *line = NULL;
	size_t size;

	size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);

}
