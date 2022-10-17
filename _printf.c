#include "main.h"

/**
 * determine_function - determines a function depending on the type of specifier passed
 * @format: a specifier.
 * Return: a right function or NULL
 */
int (*determine_function(const char *format))(va_list)
{
	print_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percentage},
		{"i", print_integer},
		{"d", print_decimal},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_heXadecimal},
		{"S", print_String},
		{"R", print_rot13},
		{"p", print_address},
		{NULL, NULL}};
	int i;

	i = 0;
	while (find_f[i].s)
	{
		if (find_f[i].s[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - prints formated statement
 * @format: format to be printed
 * Return: size
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
}
