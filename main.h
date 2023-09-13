#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>
char **get_args(char *, char *);
char *str_dup(char *);
int str_cmp(char *, char *);
int str_len(char *);
char *concat(char *, char *);
char *get_env(char *);
char *get_path(char *);
void free_args(char **);

#endif /*MAIN_H*/