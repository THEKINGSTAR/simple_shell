#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

char *get_line(void);
char **split_line(char *line);
void prompt(void);
char **split_path(char *line);
char **find_exe_file(char *line);
char *find_file(char *fn, char **p);
int exe(char **args, char **paths, char **env);
void _printenv(char **envp);

#endif
