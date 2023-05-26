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
char **split_path(char **line);
char **find_exe_file(char *line);
char *find_file(char *fn, char **p);
int exe(char **args, char *path, char **env);
void _printenv(char **envp);
int is_path(char *args);
int is_empty_input(char *line);
char *_get_path(char **env);
void ctrl_d(char *line);
void remove_newline(char *str);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void _puts(char *str);
int _strcmp(char *str1,char *str2);
int _putchar(char c);
char *_strdup(char *str);

#endif
