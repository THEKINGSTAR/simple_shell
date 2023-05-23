#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>


char *get_line(void);
void exe(char **line, char **x);
char **split(char *line);
char **split_path(char *x);
char *find_file(char *file_name, char **x);
void _free(char **grid);
char *read_line_by_char(void);
char *split_arg(char *line);

void execute(char **line_splited, char **path);

#endif

