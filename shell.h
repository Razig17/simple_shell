#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(char *env);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void print(char *s);
void execute(char **argv);
char **tokenize(char *line);
void interactive(char **av);
void non_interactive(char **av);
char *get_path(char *command);
int check_builtins(char **argv);
void handle_builtins(char **argv);

#endif /* SHELL_H */
