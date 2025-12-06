#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * 3-cp.c
 *
 * This program copies the content of one file into another.
 *
 * Features:
 * - Takes two arguments: file_from and file_to.
 * - Reads data from file_from in chunks of 1024 bytes.
 * - Writes the data into file_to (creates/truncates as needed).
 *
 * Error Handling:
 * - Exit 97: wrong argument count → prints "Usage: cp file_from file_to".
 * - Exit 98: cannot read from file_from.
 * - Exit 99: cannot write to file_to.
 * - Exit 100: cannot close a file descriptor.
 *
 * Permissions:
 * - Created file_to has permissions rw-rw-r-- (0664).
 *
 * Notes:
 * - Uses dprintf to print error messages to STDERR.
 * - Uses open(), read(), write(), close() system calls.
 * - Ensures proper cleanup on error (closing file descriptors when needed).
 */
void check_args(int ac)
{
if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}
void check_read(ssize_t r, char *file, int fd)
{
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
if (fd != -1)
close(fd);
exit(98);
}
}
/**
 * check_write - checks for write errors
 * @w: number of bytes written
 * @file: name of the file
 * @fd_from: source file descriptor (closed on error)
 * @fd_to: destination file descriptor (closed on error)
 *
 * If writing fails, prints an error message to STDERR,
 * closes both file descriptors, and exits with code 99.
 */
void check_write(ssize_t w, char *file, int fd_from, int fd_to)
{
if (w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
if (fd_from != -1)
close(fd_from);
if (fd_to != -1)
close(fd_to);
exit(99);
}
}
int main(int ac, char **av)
{
int fd_from, fd_to;
ssize_t r, w;
char buffer[1024];
check_args(ac);
fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
exit(98);
}
fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
close(fd_from);
exit(99);
}
while ((r = read(fd_from, buffer, 1024)) > 0)
{
w = write(fd_to, buffer, r);
check_write(w, av[2], fd_from, fd_to);
}
/**
 * check_read - checks for read errors
 * @r: number of bytes read
 * @file: name of the file
 * @fd: file descriptor to close on failure
 *
 * If reading fails (r == -1), prints an error message to STDERR,
 * closes the file descriptor if open, and exits with code 98.
 */
check_read(r, av[1], fd_from);
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}
return (0);
}
