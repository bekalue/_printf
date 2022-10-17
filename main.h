#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* Struct */
/**
 * struct print - struct to choose the right function depending
 * on the format specifier passed to _printf().
 * @s: format specifier
 * @f: pointer to the correct printing function
 */
struct print
{
	char *s;
	int (*f)(va_list);
};
typedef struct print print_f;

/* Functions */
int _putchar(char);
int _printf(const char *format, ...);
int print_string(va_list);
int print_percentage(va_list);
int print_char(va_list);
int print_num(va_list);
int print_String(va_list);
int print_address(va_list);
int print_unsigned_int(va_list);
int print_binary(va_list);
int print_octal(va_list);
int print_hexadecimal(va_list);
int print_heXadecimal(va_list);
int print_reversed(va_list);
int print_rot13(va_list);

#endif
