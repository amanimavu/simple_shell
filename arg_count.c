#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * get_arg_count - gets the count of user input in the shell
 * @user_input: pointer to a pointer to the user input
 *
 * Return: count of the arguments
 */

size_t get_arg_count(char *user_input)
{
	char user_input_cpy[strlen(user_input)];
	size_t count = 0;

	strcpy(user_input_cpy, user_input);
	char *token = strtok(user_input_cpy, " ");

	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}
	return (count);
}
