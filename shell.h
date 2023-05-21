#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

char *get_line(void);
void exe(char **line);
char **split(char *line);
char **handle_path();
int find_file(char *dir_name, char *file_name);

#endif
