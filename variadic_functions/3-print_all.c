#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
	* print_char - prints a char
	*/
void print_char(va_list ap)
{
printf("%c", va_arg(ap, int));
}
/**
	* print_int - prints an int
	*/
void print_int(va_list ap)
{
printf("%d", va_arg(ap, int));
}
/**
	* print_float - prints a float
	*/
void print_float(va_list ap)
{
printf("%f", va_arg(ap, double));
}
/**
	* print_string - prints a string
	*/
void print_string(va_list ap)
{
char *s = va_arg(ap, char *);
if (!s)
s = "(nil)";
printf("%s", s);
}
/**
	* print_all - prints anything
	*/
void print_all(const char * const format, ...)
{
va_list ap;
int i = 0, j;
char *sep = "";
struct spec
{
char t;
void (*f)(va_list);
} ops[] = {
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
