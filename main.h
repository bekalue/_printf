#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print - defines a new struct
 * @string: string passed by argument
 * @func: function type
 *
 * Description: above
 */

typedef struct print
{
	char string;
	int (*func)(va_list);
} print_f;

int _printf(const char *format, ...);

int _putchar(char c);

int c_printf(va_list arg);

int s_printf(va_list arg);

int number_printf(va_list arg);

int number_printf(va_list arg);

int unsigned_printf(va_list arg);

int reverse_printf(va_list arg);

int rot13_printf(va_list arg);

#endif