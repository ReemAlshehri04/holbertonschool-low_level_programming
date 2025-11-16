#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - prints a char
 * @ap: argument list
 */
void print_char(va_list ap)
{
printf("%c", va_arg(ap, int));
}
/**
 * print_int - prints an integer
 * @ap: argument list
 */
void print_int(va_list ap)
{
printf("%d", va_arg(ap, int));
}
/**
 * print_float - prints a float
 * @ap: argument list
 */
void print_float(va_list ap)
{
printf("%f", va_arg(ap, double));
}
/**
 * print_string - prints a string
 * @ap: argument list
 */
void print_string(va_list ap)
{
char *s;
s = va_arg(ap, char *);
if (s == NULL)
s = "(nil)";
printf("%s", s);
}
/**
 * struct specifier - maps a type symbol to its printer function
 * @t: the format type character (c, i, f, s)
 * @f: pointer to a function that prints the corresponding type
 *
 * Description: This struct allows linking format specifiers with
 * the correct printing function to handle variadic arguments.
 */
struct specifier
{
char t;
void (*f)(va_list);
};
/**
 * print_all - prints anything based on provided format
 * @format: list of argument types
 *
 * Description: c = char, i = int, f = float, s = string.
 * Unknown format characters are ignored.
 */
void print_all(const char * const format, ...)
{
va_list ap;
int i = 0, j;
char *sep = "";
struct specifier ops[] = {
{'c', print_char},
{'i', print_int},
{'f', print_float},
{'s', print_string}
};
va_start(ap, format);
while (format && format[i])
{
j = 0;
while (j < 4)
{
if (format[i] == ops[j].t)
{
printf("%s", sep);
ops[j].f(ap);
sep = ", ";
}
j++;
}
i++;
}
printf("\n");
va_end(ap);
}
