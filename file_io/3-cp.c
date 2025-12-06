#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
/**
	* error_exit - Print an error message to STDERR and exit
	* @code: exit code to use
	* @msg: error message format string
	* @arg: argument inserted in the message (file name or file descriptor)
	*
	* Description: This function prints an error message using dprintf
	* to the POSIX standard error and exits the program with the given code.
	* It is used to avoid repeating error-handling code.
	*/
void error_exit(int code, const char *msg, const char *arg)
{
dprintf(STDERR_FILENO, msg, arg);
exit(code);
}
/**
	* main - Entry point, copies content from one file into another
	* @argc: number of arguments
	* @argv: argument vector, should contain source and destination file names
	*
	* Return: 0 on success.
	*
	* Description:
	* This program replicates the behavior of the cp command.
	* It reads 1,024 bytes at a time from file_from and writes them into file_to.
	* It handles all errors related to argument count, file opening, reading,
	* writing, and closing, printing the required messages and exiting with
	* the correct exit codes as specified in the project instructions.
	*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_t r, w;
char buffer[1024];
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
close(fd_from);
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}
while ((r = read(fd_from, buffer, 1024)) > 0)
{
w = write(fd_to, buffer, r);
if (w != r)
{
close(fd_from);
close(fd_to);
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}
}
if (r == -1)
{
close(fd_from);
close(fd_to);
error_exit(98, "Error: Can't read from file %s\n", argv[1]);
}
if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd %s\n", argv[1]);
if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd %s\n", argv[2]);
return (0);
}
