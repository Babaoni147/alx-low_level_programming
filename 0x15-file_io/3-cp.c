#include "main.h"

void stat_check(int open_fd, int fd, char *filename, char mode);
/**
 * main - function that copies the content of one file to another file
 * @argc: The argument number
 * @argv: The argument input
 * Return: 1 (Success)
 */
int main(int argc, char *argv[])
{
	int sor, r = 1024, destn, w, clo_sor, clo_destn;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: op file_from file to\n");
		exit(97);
	}
	sor = open(argv[1], O_RDONLY);
	stat_check(sor, -1, argv[1], 'O');
	destn = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	stat_check(destn, -1, argv[2], 'W');
	while (r == 1024)
	{
		r = read(sor, buff, sizeof(buff));
		if (r == -1)
			stat_check(-1, -1, argv[1], 'O');
		w = write(destn, buff, r);
		if (w == -1)
			stat_check(-1, -1, argv[2], 'W');
	}
	clo_sor = close(sor);
	stat_check(clo_sor, sor, NULL, 'O');
	clo_destn = close(destn);
	stat_check(clo_destn, destn, NULL, 'C');
	return (0);
}

/**
 * stat_check - function that check if a file will be opened or closed
 * @open_fd: file descriptor of file to be opened
 * @filename: name of file
 * @fd: file descriptor
 * @mode: closing or opening
 * Return: void
 */
void stat_check(int open_fd, int fd, char *filename, char mode)
{
	if (mode == 'C' && open_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	else if (mode == 'O' && open_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && open_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
