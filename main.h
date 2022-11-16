#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
void execute(char *user_input, char *env[]);
size_t get_arg_count(char *);
char *get_user_input(void);
void looping_prompt(char *env[]);

#endif /*MAIN_H*/
