#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - entry point of program
 * @ac: argument count
 * @av: argument vector
 * @envp: envronment variables of the terminal
 *
 * Return: 0 implying success
 */

int main(__attribute__((unused)) int ac,
		__attribute__((unused)) char **av, char *envp[])
{
	char *buf;
	int bytes_read;

	if (!isatty(STDIN_FILENO))
	{
		buf = malloc(sizeof(char) * 1024);
		bytes_read = read(STDIN_FILENO, buf, 1024);
		if (bytes_read == -1)
		{
			free(buf);
			perror("shell_non-interactive: ");
			exit(EXIT_FAILURE);
		}
		buf[strcspn(buf, "\n")] = 0;
		execute(&buf, envp, av);
	}
	else
	{
		looping_prompt(envp, av);
	}

	return (0);
}

