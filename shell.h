#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void print(char *s);
void execute(char **argv);
char **tokenize(char *line);

#endif /* SHELL_H */
