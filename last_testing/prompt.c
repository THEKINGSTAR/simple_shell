#include "shell.h"

/**

prompt - Print prompt.
Return: Void.
*/
void prompt(void)
{
if (isatty(STDIN_FILENO))
{
_puts("(s) ");
}
}
