#include "shell.h"

int exe(char **args, char **w, char **envp)
{
	pid_t pid;
	int status, i, x, flag = 0;
	char *path;
	char **splited_first = NULL;
	for (i = 0; args[0][i] != '\0'; i++)
	{
		if (args[0][i] == '/')
		{
		    	int fd = access(args[0], F_OK);
			if (fd == -1)
			{
				flag = 1;
				break;
			}
		}
	}
	splited_first = find_exe_file(args[0]);
	for (i = 0; splited_first[i] != NULL; i++)
	{
	}
	path = find_file(splited_first[i - 1], w);
	if (strcmp(path, "0") == 0 || flag == 1)
	{
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		x = execve(path, args, envp);
		if(x == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		
	}
	else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
        }
	}
	return (0);
}
