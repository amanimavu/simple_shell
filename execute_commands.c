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

int execute(char **user_input, char *env[], char **av)
{
	char **argv, *custom_err;
	pid_t id;

	argv = tokenize(user_input);
	if (!strcmp(argv[0], "exit"))
	{
		free(argv);
		return (1);
	}

	id = fork();
	if (id == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			custom_err = malloc(sizeof(char) * (strlen(av[0]) + strlen(": ") + 1));
			strcpy(custom_err, av[0]);
			perror(custom_err);
			free(custom_err);
		}
		free(*user_input);
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(argv);
	}
	return (0);
}

