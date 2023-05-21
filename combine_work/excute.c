#include "shell.h"

void excute(char **x)
{
	pid_t pid;
	int status;
	pid = fork();
	if (pid < 0)
	{
		printf("the error occured\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if ((execve(x[0], x, NULL)) == -1)
		{
			printf("commaned is not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
}
