#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 if success or 1 others
 */
int main(void)
{
	char *line;
	char **line_splited;

	do {
		printf("($) ");
		line = get_line();
		line_splited = split(line);
		exe(line_splited);
		free(line);
		free(line_splited);
	} while (1);
	return (EXIT_SUCCESS);
}
