#include "shell.h"

/**
* main - entry point
*
* Return: 0 if success or 1 others
*/
int main(void)
{
	int i;
	char *line;
	char **line_splited;
	char **path;
	char *x;
	const char *envp[] = {NULL};

	while(1)
	{
		printf("($) ");
		line = get_line();
		line_splited = split(line);
		path = handle_path();
		for (i = 0; path[i] != NULL; i++)
		{
			if ((find_file(path[i], line_splited[0])) == 1)
			{
				strcat(path[i], "/");
				strcat(path[i], line_splited[0]);
				break;
			}
		}
		if (fork() == 0)
		{
			execve(path[i], line_splited, (char * const *)envp);
			printf("%s %s\n", path[i], line_splited[0]);
			perror("hsh");
			exit(EXIT_FAILURE);
		}
		wait(NULL);
	}
		return (0);
}
