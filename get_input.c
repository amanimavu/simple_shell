#include <stdio.h>

/**
 * get_user_input - retrieves input from a user in the terminal
 * Return: void
 */

void get_user_input(void)
{
	char *buf = NULL;
	size_t buf_size = 0;

	getline(&buf, &buf_size, stdin);
}
