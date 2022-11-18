#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * get_arg_count - gets the count of user input in the shell
 * @user_input: pointer to a pointer to the user input
 *
 * Return: count of the arguments
 */

size_t get_arg_count(char *user_input)
{
	char *user_input_cpy;
	char *token;
	size_t count;

	user_input_cpy = malloc(sizeof(char) * strlen(user_input));
	strcpy(user_input_cpy, user_input);
	token = strtok(user_input_cpy, " ");
	count = 0;
	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}
	free(user_input_cpy);
	return (count);
}
