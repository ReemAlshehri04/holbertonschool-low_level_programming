#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdarg.h>
/**
 * struct specifier - maps a type symbol to print function
 * @t: type character
 * @f: pointer to printer function
 */
typedef struct specifier
{
char t;
void (*f)(va_list);
} spec_t;
void print_all(const char * const format, ...);
#endif
