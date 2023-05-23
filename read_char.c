#include "shell.h"

/**
 * read_line_by_char - read by character
 * Return: return the readed
 */
char *read_line_by_char(void)
{
	int bufsize = 1024;
	char *line;
	int c;
	int position = 0;
	size_t nread, size;

	line = malloc(sizeof(char) * bufsize);
	if (line == NULL)
	{
		fprintf(stderr, "error to alloc memory");
		exit(EXIT_FAILURE);
	}
	nread = getline(&line, &size, stdin);
	if (nread != 0)
	{
		fprintf(stderr, "error to alloc memory");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = line[position];
		if (c == EOF || c == '\n')
		{
			line[position] = '\0';
			return (line);
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += 1024;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "error to alloc memory");
				exit(EXIT_FAILURE);
			}
		}
	}
}
