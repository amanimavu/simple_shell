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
	int mode;
	char *prompt;
	char *user_input;

	mode = isatty(STDIN_FILENO);
	prompt = "#cisfun$ ";
	while (mode)
	{
		if (mode == 1)
		{
			write(STDIN_FILENO, prompt, strlen(prompt));
			user_input = get_user_input();

			execute(user_input, env, av);
		}
		free(user_input);
	}
}

