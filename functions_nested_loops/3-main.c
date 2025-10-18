#include "main.h"
#include <stdio.h>
/**
 * main - Entry point for the test program.
 *
 * Return: Always 0.
 */
int main(void)
{
int r;
/* Test with uppercase 'H'. Expected output: 0 */
r = _islower('H');
putchar(r + '0');
/* Test with lowercase 'o'. Expected output: 1 */
r = _islower('o');
putchar(r + '0');
/* Test with integer ASCII value 108 (which is 'l'). Expected output: 1 */
r = _islower(108);
putchar(r + '0');
/* Test with non-lowercase 'L'. Expected output: 0 */
r = _islower('L');
putchar(r + '0');
/* Test with lowercase 'e'. Expected output: 1 */
r = _islower('e');
putchar(r + '0');
/* Print a newline character */
putchar('\n');
return (0);
}
