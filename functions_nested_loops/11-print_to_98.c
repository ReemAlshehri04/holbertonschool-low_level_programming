#include "main.h"
#include <stdio.h>
`/**
 * print_to_98 - Prints all natural numbers from n to 98.
 * @n: The starting number.
 *
 * Description: Numbers are separated by a comma and a space.
 * The last number (98) is followed by a new line.
 * Uses the standard library (stdio.h).
 * Return: void
 */
void print_to_98(int n)
{
int i;
if (n <= 98)
{
for (i = n; i <= 98; i++)
{
printf("%d", i);
if (i != 98)
{
printf(", ");
}
}
}
else /* n > 98 */
{
for (i = n; i >= 98; i--)
{
printf("%d", i);
if (i != 98)
{
printf(", ");
}
}
}
printf("\n");
}
