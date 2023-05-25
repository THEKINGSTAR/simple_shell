#include "shell.h"
/**
 * split_arg - split functi
 * @line:input line
 * Return: return splited line
 */

char *split_arg(char *line)
{
	int bufsize = 64, position = 0;
	char *token, **tokens = malloc(bufsize * sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "error in memory allocation::split_args");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "/");
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "error in memory allocation::split_arg");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, "/");
	}
	return (tokens[position - 1]);
}
