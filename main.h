#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int print_char(va_list args);
int print_string(va_list args);
int print_p(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);
/**
 * struct prt - struct that contains functions.
 * @str: string that contains the format.
 * @f: function of specific type.
 */

typedef struct prt
{
	char *str;
	int (*f)(va_list args);
} print;
#endif
