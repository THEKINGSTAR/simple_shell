#include "shell.h"

/**
 * split_path- split
 * @line:line to split
 * Return: return the splited line
 */

char **split_path(char *line)
{
	int bufsize = 64;
	int position;
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		fprintf(stderr, "error in memory allocation:: split path");
		exit(EXIT_FAILURE);
	}
	position = 0;
	token = strtok(line, ":");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize);
			if (tokens == NULL)
			{
				fprintf(stderr, "error in memory allocation::split path");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, ":");
	}
	tokens[position] = NULL;
	return (tokens);
}
