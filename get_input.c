#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * get_user_input - retrieves input from a user in the terminal
 *
 * Return: void
 */

char *get_user_input(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	const char *error_text = "getline failed";
	int bytes_written, char_read = getline(&buf, &buf_size, stdin);

	if (char_read == -1)
	{
		bytes_written = write(STDERR_FILENO, error_text, strlen(error_text) + 1);
		if (bytes_written == -1)
		{
			perror("get_input: ");
		}
		exit(EXIT_FAILURE);
	}
	/*buf[strcspn(buf, "\n")] = 0;*/
	buf[char_read - 1] = 0;

	return (buf);
}

