#include "shell.h"

int exe(char **args, char *path, char **envp)
{
	int status, x;
	

	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		x = execve(path, args, envp);
		if(x == -1)
		{
			exit(EXIT_FAILURE);
		}
		
	}
	else {
		wait(&status);

        }
	return (0);
}
