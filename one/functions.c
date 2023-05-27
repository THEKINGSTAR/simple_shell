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

/**
 * is_path - is this path
 * @args: 1
 *
 * Return: int
 */
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

/**
 * is_empty_input - empty
 * @line: 1
 *
 * Return: int
 */
int is_empty_input(char *line)
{
	int i;
	int x;
	int z = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (_strcmp(line, "\n") == 0)
			return (1);
		remove_newline(line);
		x = _strlen(line);
		if (line[i] == ' ')
		{
			z++;
		}
		if (z == x)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * remove_newline - remove last
 * @str: 1
 *
 * Return: non
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
