#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int fn_unk(va_list list);
int (*print_sel(char idsel))(va_list);
int _pwr(int, int);
int _print_c(va_list list);
int _print_c(va_list list);
int _print_s(va_list list);
int _print_mod(va_list list);
int _print_i(va_list list);
int _print_ui(va_list list);
int _print_b(va_list list);
int _print_o(va_list list);

/**
 * struct structu - struct as a selector to char and to function pointer as args
 * @argument: argument selector
 * @f: functions
 */
typedef struct structu
{
	char *argument;
	int (*f)(va_list list);
} id;

#endif