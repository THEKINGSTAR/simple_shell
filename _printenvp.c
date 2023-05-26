#include "shell.h"
/**
 * _printenv - print enviroment
 *
 */
void _printenv(char **envp)
{
        int i = 0;

        while (envp[i] != NULL)
        {
                write(1, envp[i], _strlen(envp[i]));
                write(1, "\n", 1);
                i++;
        }
}

