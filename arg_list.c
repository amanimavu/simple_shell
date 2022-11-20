#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * tokenize - splits the user_input into token of string
 * @input: user input read from the stream
 *
 * Return: list of tokens
 */

char **tokenize(char **input)
{
	size_t ac;
	char **token_list, *token;
	int count;

	ac = get_arg_count(*input);
	token_list = malloc(sizeof(char *) * (ac + 1));
	count = 0;
	token = strtok(*input, " ");
	while (token)
	{
		token_list[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	token_list[count] = NULL;
	return (token_list);
}

