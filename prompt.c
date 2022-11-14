#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * looping_prompt - generate a prompt for user continuously
 * Return: nothing
 */

void looping_prompt(void)
{
	int mode = isatty(STDIN_FILENO);
	char *prompt = "#cisfun$ ";

	while (mode)
	{
		if (mode == 1)
		{
			write(STDIN_FILENO, prompt, strlen(prompt));
			get_user_input();
		}
	}
}

