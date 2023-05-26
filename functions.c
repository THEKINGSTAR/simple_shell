#include "shell.h"

/**
 * prompt - check the input form terminal or file
 *
 * Return: none
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
	}
}

int is_path(char *args)
{
	int i;
	int fd;
	for (i = 0; args[i] != '\0'; i++)
        {
                if (args[i] == '/')
                {
                        fd = access(args, F_OK);
                        if (fd == -1)
                        {
				return (1);
                                
                        }
                }
        }
	return (0);
}

int is_empty_input(char *line)
{
	int i;
	int x;
	int z = 0;

	x = _strlen(line);
	for(i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
		{
			z++;
		}
		if (z == x || _strcmp(line, "\n") == 0)
		{
			return (1);
		}
	}
	return (0);
}	
