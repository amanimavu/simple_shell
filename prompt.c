#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * looping_prompt - generate a prompt for user continuously
 * @env: terminal environment variable
 * @av: argument vetor
 *
 * Return: nothing
 */

void looping_prompt(char *env[], char **av)
{
	int bytes_written, toggle = 1;
	char *prompt;
	char *user_input;

	prompt = "#cisfun$ ";
	while (toggle)
	{

		bytes_written = write(STDIN_FILENO, prompt, strlen(prompt) + 1);
		if (bytes_written == -1)
		{
			perror("prompt: ");
			exit(EXIT_FAILURE);
		}
		user_input = get_user_input();
		if (!strlen(user_input))
		{
			free(user_input);
			user_input = NULL;
			continue;
		}
		if (execute(&user_input, env, av))
			toggle = 0;
		free(user_input);
		user_input = NULL;
	}
}

/**
 * free_mem - frees memory allocated by malloc
 * @mem_alloc: memory allocated by malloc
 * Return: nothing
 */
