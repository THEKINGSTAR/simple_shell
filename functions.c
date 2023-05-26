#include "shell.h"

/**
 * prompt - check the input form terminal or file
 *
 * Return: none
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
	{
		write(1, "($) ", 4);
	}
	else
	{
		return;
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
			else
			{
				return (2);
			}
                }
        }
	return (0);
}

int is_empty_input(char *line)
{
	int i;
	int x;

	x = _strlen(line);
	for(i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
		{
			i++;
		}
		if (i == x)
		{
			return (1);
		}
	}
	return (0);
}
	
