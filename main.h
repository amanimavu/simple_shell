#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
int execute(char **user_input, char *env[], char **av);
size_t get_arg_count(char *);
char *get_user_input(void);
void looping_prompt(char *env[], char **av);

#endif /*MAIN_H*/
