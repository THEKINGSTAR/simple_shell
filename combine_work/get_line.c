#include "shell.h"

char *get_line(void)
{
	int i;
	char *line = NULL;
	size_t nread = 0;

	i = getline(&line, &nread, stdin);
	if (i == -1)
	{
	if (feof(stdin))
	{
		printf("bravo");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("yaaaaaaaa3");
		exit(EXIT_FAILURE);
	}
	}
	line[strlen(line) - 1] = '\0';
	return (line);

}	
