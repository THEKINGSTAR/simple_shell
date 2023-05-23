#include "shell.h"

/**
 * _exiting - exit function
 * @line:buffer to free
 * @line_splited: splite line
 * @path: path of the env
 */
void _exiting(char *line, char **line_splited, char **path)
{
	free(line);
	_free(line_splited);
	_free(path);
	exit(EXIT_SUCCESS);
}
