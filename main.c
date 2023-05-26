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
	char *line = NULL, **tokens = NULL, **paths = NULL, *sp = NULL;
	int z;	
	(void)argv;
	(void)argc;
	while (1)
	{
		prompt();
		line = get_line();
		if (line != NULL && is_empty_input(line) == 0)
		{
			remove_newline(line);
			tokens = split_line(line);
			if (_strcmp(tokens[0], "exit") == 0)
				break;
			if (_strcmp(tokens[0], "env") == 0)
                	{
                        	_printenv(envp);
                	}
			else
			{
				z = is_path(tokens[0]);
				sp = tokens[0];
				if (z == 0)
				{
					paths = split_path(envp);
					sp = find_file(tokens[0], paths);
				}
				if (z == 1 || (z == 0 && strcmp(sp, "0") == 0))
					puts("command not found");
				else if(z == 2 || (z == 0 && strcmp(sp, "0") != 0))
					exe(tokens, sp, envp);
				free(line);
				free(tokens);
			}
		}
	}
	return (EXIT_SUCCESS);
}
