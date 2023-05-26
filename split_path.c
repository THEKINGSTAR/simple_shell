#include "shell.h"

/**
 * split_path - split line to argument
 * @env: line from user
 *
 * Return: array of string
 */
char **split_path(char **env)
{
	char *line;
	char **tokens = NULL;
	char *token = NULL;
	size_t i, j;
	int count = 0;

	line = _get_path(env);

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ':')
			count++;
	}
	if ((count + 1) == _strlen(line))
		return (NULL);
	tokens = (char **)malloc(sizeof(char *) * (count + 2));
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, ":");
	j = 0;
	while (token != NULL)
	{
		tokens[j] = token;
		j++;
		token = strtok(NULL, ":");
	}
	tokens[j] = NULL;
	return (tokens);
}
