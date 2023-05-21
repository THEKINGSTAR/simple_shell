#include "shell.h"

void exe(char **x)
{
	pid_t pid;
	char **y;
	int status, i, z;

	y = handle_path();
	for (i = 0; y[i] != NULL; i++)
	{
		z = find_file(y[i], x[0]);
		if (z == 1)
			break;
	}
	pid = fork();
	if (pid < 0)
	{
		printf("the error occured\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if ((execve("/bin/ls", x, NULL)) == -1)
		{
		printf("commaned is not found %s\n", y[i]);
		exit(EXIT_FAILURE);
		}
		
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	
}
