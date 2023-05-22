#include "shell.h"


int execute(char  **line_splited, char **path)
{

        int i, j, flag;
        char *line; 
        const char *envp[] = {NULL};

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
		                else
                {
                        free_grid (line_splited);
                        free_grid(path);
                }
                wait(NULL);

}

