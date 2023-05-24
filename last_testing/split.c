#include "shell.h"

/**
 * split_line - split function
 * @line:line to split
 * Return:return tokens
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int position;
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char *) * bufsize);
	if (tokens == NULL)
	{
		perror("allocating");
		exit(EXIT_FAILURE);
	}
	position = 0;
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/**if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize);
			if (tokens == NULL)
			{
				fprintf(stderr, "error in memory allocation");
				exit(EXIT_FAILURE);
			}
		}*/
		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}
