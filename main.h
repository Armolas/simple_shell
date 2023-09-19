#ifndef MAIN_H
#define MAIN_H
extern char **environ;
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
void free_args(char **, int);
void p_error(char *);
int count_args(char **);
int _pow_recursion(int x, int y);
int string_to_int(char *str);
int are_digits(char *str);
int exit_arg(char **, char *, int);
int null_arg(char **, char *, char *, int);
int child_fail(char **, char *, int);
void penv(char **, int);
void _puts(char *);
int fork_child(char **, char **, char *, int);
#endif /*MAIN_H*/
