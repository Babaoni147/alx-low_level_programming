#include "main.h"

/**
 * create_file - function that create a file
 * @filename: The name of the file to be created
 * @text_content: Pointer to a NUL terminated string to write into the file
 * Return: 1 (Success)
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, c = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (c = 0; text_content[c];)
			c++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, c);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
