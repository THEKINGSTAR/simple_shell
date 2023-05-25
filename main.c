#include "shell.h"

/**
 * main - entry point
 *
 * @argc: first paramter
 * @argv: second paramter
 * @envp: third paramter
 *
 * Return: 0 if success
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	char **tokens = NULL;
	char *path = NULL;
	char **paths = NULL;
	char **path_splited = NULL;
	
	int errno = 0;

	(void)argc;
	(void)argv;
	path = getenv("PATH");
	paths = split_path(path);
	while (1)
	{
		prompt();
		line = get_line();
		if (line == NULL)
			return (0);
		if (strcmp(line, "env") == 0)
		{
			_printenv(envp);
		}
		tokens = split_line(line);
		
		errno = exe(tokens, paths,envp);
		if (errno == 1)
			exit(EXIT_FAILURE);
		free(line);
		free(tokens);
		free(path_splited);
	
	}
	free(paths);
	return (EXIT_SUCCESS);
}
