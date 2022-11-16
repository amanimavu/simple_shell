#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * looping_prompt - generate a prompt for user continuously
 * @env: terminal environment variable
 * Return: nothing
 */

void looping_prompt(char *env[])
{
	int mode = isatty(STDIN_FILENO);
	char *prompt = "#cisfun$ ";
	const char *err_text = "An error occurred when getting user input";

	while (mode)
	{
		if (mode == 1)
		{
			write(STDIN_FILENO, prompt, strlen(prompt));
			char *user_input = get_user_input();

			if (!user_input)
			{
				perror(err_text);
				exit(EXIT_FAILURE);
			}
			execute(user_input, env);
		}
	}
}

