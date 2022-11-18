#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - entry point of program
 * @ac: argument count
 * @av: argument vector
 * @envp: envronment variables of the terinal
 *
 * Return: 0 implying success
 */

int main(__attribute__((unused)) int ac,
		__attribute__((unused)) char **av, char *envp[])
{
	char *buf = malloc(sizeof(char) * 1024);

	if (!isatty(STDIN_FILENO))
	{
		read(STDIN_FILENO, buf, 1024);
		buf[strcspn(buf, "\n")] = 0;
		execute(buf, envp, av);
		free(buf);
	}
	looping_prompt(envp, av);

	return (0);
}
