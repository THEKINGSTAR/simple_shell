#include "shell.h"
/**
 * exe - execute function
 *
 * @args: argumnet to exec
 * @w: characters
 * @env: theinvironment
 */
void exe(char **args, char **w, char **envp)
{
	int status, i, x, flag = 0;
	char *path, *sp_arg;
	pid_t pid;
	

	for (i = 0; args[0][i] != '\0'; i++)
	{
		if (args[0][i] == '/')
		{
			int fd = access(args[0], F_OK);

			if (fd == -1)
			{	flag = 1;
				break;	}
		}
	}
	sp_arg = split_arg(args[0]);
	path = find_file(sp_arg, w);
	if (_strcmp(path, "0") == 0 || flag == 1)
	{
		perror(args[0]);
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		x = execve(path, args, envp);
		free(path);
		if (x == -1)
		{	perror("execve");
			exit(EXIT_FAILURE);	}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{	perror("waitpid");	}
	}
}
