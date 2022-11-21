#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * free_in_execute - free allocated memory in function execute
 * @user_input: user's input
 * @argv: argument vector
 *
 * Return: nothing
 */
void free_in_execute(char **user_input, char **argv)
{
	char first_5[6];

	strncpy(first_5, *user_input, 5);
	first_5[5] = '\0';
	if (!strcmp(first_5, "/bin/") || !strcmp(argv[0], "exit"))
	{
		free(argv);
		free(*user_input);
	}
	else
	{
		free(argv[0]);
		free(argv);
		free(*user_input);
	}
}
