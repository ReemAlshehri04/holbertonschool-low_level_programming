#include <stdio.h>
/**
 * main - Prints all the numbers of base 16 in lowercase
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
int num;
char letter;
/* print 0-9 */
for (num = 0; num < 10; num++)
putchar(num + '0');
/* print a-f */
for (letter = 'a'; letter <= 'f'; letter++)
putchar(letter);
putchar('\n');
return (0);
}
