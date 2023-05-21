#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char *get_line(void);
int excute(char **line);
char **split(char *line);
char *read_line_by_char(void);

#endif
