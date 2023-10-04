#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: Name of file to append to
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 (Success)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i, w, c = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (c = 0; text_content[c];)
			c++;
	}

	i = open(filename, O_WRONLY | O_APPEND);
	w = write(i, text_content, c);

	if (i == -1 || w == -1)
		return (-1);

	close(0);

	return (1);
}
