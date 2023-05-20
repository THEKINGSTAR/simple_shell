#include "shell.h"

char **split(char *line)
{
	char **tokens = NULL;
	char *token = strtok(line, " ");
	int count = 0;

	while (token != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		tokens[count] = malloc(strlen(token + 1));
		strcpy(tokens[count], token);
		count ++;
		token  = strtok (NULL, " ");

	}
	tokens = realloc(tokens , (count + 1) * sizeof(char *));
	tokens[count] = NULL;

	return (tokens);
}
