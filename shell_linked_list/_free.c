#include "shell.h"
/**
 * _free - free line function
 *
 * @command: input command
 *
 * Descrition: free the input line
 * Return: function has no return value
 */
void _free(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}
