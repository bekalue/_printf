#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

/**
 * struct op - structure
 * @func: format
 * @f: pointer to func
 * list-> list of functions
 */
typedef struct op
{
	char *func;
	int (*f)(va_list);
} op_t;

int _putchar(char c);
int (*get_func(char))(va_list list);
int _printf(const char *format, ...);
int _printf_u(va_list list);
int _printf_c(va_list list);
int _printf_s(va_list list);
int _printf_d_i(va_list list);
int _printf_r(va_list list);
int _printf_13(va_list list);
int _printf_x(va_list list);
int _printf_X(va_list list);
int _printf_o(va_list list);
int _printf_b(va_list list);
int _printf_p(va_list list);
int _printf_h(va_list list);

#endif
