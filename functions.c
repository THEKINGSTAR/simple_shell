#include "shell.h"

/**
 * prompt - check the input form terminal or file
 *
 * Return: none
 */
void prompt(void)
{
	if (isatty(STDOUT_FILENO))
	{
		write(1, "($) ", 4);
	}
}
