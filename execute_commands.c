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
 *
 * Return: nothing
 */

void execute(char *user_input, char *env[])
{
	const size_t ac = get_arg_count(user_input);
	char *argv[ac];
	int count = 0;
	char *token = strtok(user_input, " ");
	char *error_message = "./shell: No such file or directory\n";

	while (token)
	{
		argv[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	argv[count] = NULL;
	/*int num = 0;
	while(argv[num])
	{
		printf("%s\n", argv[num]);
		num++;
	}*/
	pid_t id = fork();

	if (id == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			write(STDOUT_FILENO, error_message, strlen(error_message));
		}
	}
	else
	{
		wait(NULL);
	}
}
