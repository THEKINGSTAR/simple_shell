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
	char *sp = NULL;
	int z;

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
		/**if (is_empty_input(line) == 1)*/
		if (_strcmp(line, "env") == 0)
		{
			_printenv(envp);
		}
		tokens = split_line(line);
		if (tokens == NULL)
			return (0);
		z = is_path(tokens[0]);
		sp = tokens[0];
		if (z == 0)
		{
			sp = find_file(tokens[0], paths);
		
		}
		if (z == 1 || (z == 0 && strcmp(sp, "0") == 0))
			puts("command not found");
		else
			exe(tokens, sp, envp);
		free(line);
		free(tokens);
		
	}
	free(paths);
	return (EXIT_SUCCESS);
}
