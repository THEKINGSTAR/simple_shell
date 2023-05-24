#include "shell.h"
/**
 * exe - execute function
 *
 * @args: argumnet to exec
 * @w: characters
 * @env: theinvironment
 */
void exe(char **args, char **w, char **env)
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
	if (strcmp(path, "0") == 0 || flag == 1)
	{
		printf("the command yaaaaa3\n");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		x = execve(path, args, env);
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
