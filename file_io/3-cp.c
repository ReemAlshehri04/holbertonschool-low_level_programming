#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
	* close_fd - closes a file descriptor with error checking
	* @fd: file descriptor
	*/
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}
/**
	* main - copies content of one file to another
	* @argc: argument count
	* @argv: argument vector
	*
	* Return: 0 on success, exits with codes on failure
	*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t r, w;
char buffer[BUFFER_SIZE];
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
	}
/* Open source file */
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
/* Open destination file */
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_fd(fd_from);
exit(99);
}	
/* Read 1024 bytes at a time */
while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
w = write(fd_to, buffer, r);
if (w == -1 || w != r)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close_fd(fd_from);
close_fd(fd_to);
exit(99);
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close_fd(fd_from);
close_fd(fd_to);
exit(98);
}
close_fd(fd_from);
close_fd(fd_to);
return (0);
}
