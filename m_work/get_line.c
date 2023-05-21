#include "shell.h"

char *get_line(void)
{
	int i;
	char *line;
	int line_size;
	int c;

	line_size = 1024;
	line = malloc(sizeof(char) * line_size);
	if (line == NULL)
	{
		fprintf(stderr, "error to allocate memory");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		i++;
		if (i >= line_size)
		{
			line_size += 1024;
			line = realloc(line, line_size);
			if (line == NULL)
			{
				fprintf(stderr, "error to allocate memory");
				exit(EXIT_FAILURE);
			}
		}
	}
}	
