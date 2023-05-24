#include "shell.h"

/**
 * read_line_by_char - read by character
 * Return: return the readed
 */
char *read_line_by_char(void)
{
	int bufsize;
	char *line;
	int c;
	int position;
	size_t size;

	bufsize = 1024;
	position = 0;

	line = malloc(sizeof(char) * bufsize);
	if (line == NULL)
	{
		perror("allocating");
		exit(EXIT_FAILURE);
	}
	if (getline(&line, &size, stdin) == -1)
	{
		exit(EXIT_SUCCESS);
	}
	while (1)
	{
		c = line[position];
		if (c == '\n')
		{
			line[position] = '\0';
			return (line);
		}
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		position++;
		/**if (position >= bufsize)
		{
			bufsize += 1024;

			line = realloc(line, bufsize);
			if (line == NULL)
			{
				fprintf(stderr, "error to alloc memory");
				exit(EXIT_FAILURE);
			}
		}*/
	}
}
