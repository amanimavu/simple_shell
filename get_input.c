#include <stdio.h>
#include <string.h>


/**
 * get_user_input - retrieves input from a user in the terminal
 * Return: void
 */

char *get_user_input(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	const char *error_text = "getline failed";
	int char_read = getline(&buf, &buf_size, stdin);

	if (char_read == -1)
	{
		perror(error_text);
	}
	/*buf[strcspn(buf, "\n")] = 0;*/
	buf[char_read - 1] = 0;

	return (buf);
}
