#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
int execute(char **user_input, char *env[], char **av);
size_t get_arg_count(char *);
char *get_user_input(void);
void looping_prompt(char *env[], char **av);
char **tokenize(char **);
char **command_or_path(char **);
void free_in_execute(char **, char **);

#endif /*MAIN_H*/
