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

int find_file(const char *dir_name, const char *file_name);
void free_grid(char **grid);

void execute(char **line_splited, char **path);


#endif
