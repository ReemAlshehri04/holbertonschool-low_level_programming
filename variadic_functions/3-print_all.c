#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
void print_all(const char * const format, ...)
{
va_list ap;
int i = 0;
char *s;
char c;
int n;
float f;
char *sep = "";
va_start(ap, format);
while (format && format[i])
{
if (format[i] == 'c' || format[i] == 'i' ||
format[i] == 'f' || format[i] == 's')
{
printf("%s", sep);
sep = ", ";
}
if (format[i] == 'c')
{
c = (char) va_arg(ap, int);
printf("%c", c);
}
else if (format[i] == 'i')
{
n = va_arg(ap, int);
printf("%d", n);
}
else if (format[i] == 'f')
{
f = (float) va_arg(ap, double);
printf("%f", f);
}
else if (format[i] == 's')
{
s = va_arg(ap, char *);
if (!s)
printf("(nil)");
else
printf("%s", s);
}
i++;
}
va_end(ap);
printf("\n");
}
