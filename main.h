#ifndef _PRINTF_FUNCTION_H
#define _PRINTF_FUNCTION_H

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*STRUCT*/
/**
 *struct type_t - type_t_f
 *@tipo: character of specifier
 *@f: pointer to a function that we need
 */
typedef struct type_t
{
	char tipo;
	int (*f)(va_list a);
} type_t_f;

/*prototypes*/
int _putchar(char c);
int print_char(va_list s);
int print_string(va_list s);
int print_number(va_list s);
int print_number_ui(va_list i);
int print_number1(int i);
void rec_HEXA(unsigned int num);
int print_HEXA(va_list num);
void rec_hexa(unsigned int num);
int print_hexa(va_list num);
void rec_bin(unsigned int n);
int print_binary(va_list a);
int print_octal(va_list c);
int print_rot(va_list ch);
int print_rev(va_list ch);
int print_pointer(va_list c);
/*temporary*/
int output(int a, int b);

/*printf_prototype*/
int _printf(const char *format, ...);
#endif