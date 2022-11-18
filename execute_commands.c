#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute - execute commands entered by user
 * @user_input: commands entered by the user
 * @env: environmental variables
 * @av: argument vector
 *
 * Return: nothing
 */

void execute(char *user_input, char *env[], char **av)
{
	size_t ac;
	int count;
	char **argv;
	char *token;
	char *custom_err_message;
	pid_t id;

	ac = get_arg_count(user_input);
	argv = malloc(sizeof(char *) * ac);
	count = 0;
	token = strtok(user_input, " ");
	while (token)
	{
		argv[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	argv[count] = NULL;
	id = fork();
	if (id == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			custom_err_message = malloc(sizeof(char) * strlen(av[0]) * strlen(": "));
			strcpy(custom_err_message, av[0]);
			perror(custom_err_message);
			free(custom_err_message);
		}
	}
	else
	{
		wait(NULL);
	}
}