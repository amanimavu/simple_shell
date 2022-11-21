#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * command_or_path - check whether the first argument
 * has a /bin
 * @user_input: input from the user
 *
 * Return: the argument list
 */

char **command_or_path(char **user_input)
{
	char **arg_list;
	char *check_bin;
	char *the_bin;

	arg_list = tokenize(user_input);
	check_bin = strstr(arg_list[0], "/bin");
	if (check_bin != arg_list[0] && strcmp(arg_list[0], "exit"))
	{
		the_bin = malloc(sizeof(char) * (strlen("/bin/") + strlen(arg_list[0]) + 1));
		strcpy(the_bin, "/bin/");
		strcat(the_bin, arg_list[0]);
		arg_list[0] = the_bin;
	}
	return (arg_list);
}

