#include "shell.h"

void excute(char *line)
{
	pid_t pid;
	int status;
	char *x[] = {line, NULL};
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
			printf("%s commaned is not found\n",x[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
}
