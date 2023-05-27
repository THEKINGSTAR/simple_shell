#include "shell.h"

/**
 * exe - excute
 * @args: 1 pramter
 * @path: 2
 * @envp: 3
 *
 * Return: int
 */
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
		if (x == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
	return (0);
}
