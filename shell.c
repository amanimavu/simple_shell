#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <string.h>

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
	char buf[1024];
	if (!isatty(STDIN_FILENO))
	{
		read(STDIN_FILENO, buf, 1024);
		buf[strcspn(buf, "\n")] = 0;
		execute(buf, envp);
	}
	looping_prompt(envp);

	return (0);
}
