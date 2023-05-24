#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

int _putchar(char c);
int _strcmp(char *str1,char *str2);
void _puts(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**char *get_line(void);*/
void prompt(void);
void exe(char **line, char **x, char **z);
/**void exe(char **args, char **w, char **environ);*/
/**char **split(char *line);*/
char **split_line(char *line);
char **split_path(char *x);
char *find_file(char *file_name, char **x);
void _free(char **grid);
char *read_line_by_char(void);
char *split_arg(char *line);

void execute(char **line_splited, char **path);

void _exiting(char *line, char **line_splited, char **path);

#endif

