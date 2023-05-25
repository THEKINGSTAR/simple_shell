#include "shell.h"

/**
 * find_exe_file - split line to argument
 * @line: line from user
 *
 * Return: exe file
 */
char **find_exe_file(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i, j;
	int count = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '/')
			count++;
	}
	if ((count + 1) == strlen(line))
		return (NULL);
	tokens = (char **)malloc(sizeof(char *) * (count + 2));
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, "/");
	j = 0;
	while (token != NULL)
	{
		tokens[j] = token;
		j++;
		token = strtok(NULL, "/");
	}
	
	tokens[j] = NULL;
	return (tokens);
}
