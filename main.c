#include "shell.h"

/**
* main - entry point
*
* Return: 0 if success or 1 others
*/
int main(void)
{
	int i, j, flag;
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
		j = 0;
		for (i = 0; path[i] != NULL; i++)
		{
			while (line_splited[0][j])
			{
				if(line_splited[0][j] == '/')
				{
					path[i] = line_splited[0];
					flag = 1;
					break;
				}
				j++;
			}
			if (flag == 1)
				break;
			else if ((find_file(path[i], line_splited[0])) == 1)
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
