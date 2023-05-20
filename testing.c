#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    char command[20];
    char *arg[20];
    const char *envp[] = {NULL};

    while (1)
    {
        char *buffer;
        size_t bufsize = 32;
        size_t command;

        buffer = (char *)malloc(bufsize * sizeof(char));
        if (buffer == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        printf("($)");
        command = getline(&buffer, &bufsize, stdin);

        if (strcmp(buffer, "cd") == 0)
        {
            if (argv[1] != NULL)
            {
                if (chdir(arg[1]) == -1)
                {
                    perror("hsh");
                }
            }
            else
            {
                if (chdir(getenv("HOME")) == -1)
                {
                    perror("hsh");
                }
            }

            continue;
        }
        else if (strcmp(buffer, "echo") == 0)
        {
            int i = 1;
            while (arg[i] != NULL)
            {
                printf("%s ", arg[i]);
                i++;
            }

            printf("\n");

            continue;
        }
        else if (strcmp(buffer, "pwd") == 0)
        {
            char cwd[1024];

            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                printf("%s\n", cwd);
            }
            else
            {
                perror("hsh");
            }

            continue;
        }
        else if (strcmp(buffer, "exit") == 0)
        {
            break;
        }

        int i = 0;
        arg[i] = strtok(buffer, " \n");
        while (arg[i] != NULL)
        {
            i++;
            arg[i] = strtok(NULL, " \n");
        }


                if (fork() == 0)
                {
                        execve(argv[0], arg, (char * const *)envp);
                        perror("hsh");
                        exit(EXIT_FAILURE);
                }
                /* wait(NULL); */
        }
                return (0);
}
