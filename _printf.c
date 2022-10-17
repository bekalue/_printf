#include "main.h"

/**
 * find_function - determines the type of format passed
 * @format: function
 * Return: Null
 */
int (*find_function(const char *format))(va_list)
{

	print_f find_f[] = {
		{"c", print_char},
		{"%", print_percentage},
		{"s", print_string},
		{"i", print_integer},
		{"d", print_decimal},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_heXadecimal},
		{"r", print_reversed},
		{"S", print_String},
		{"p", print_address},
		{"R", print_rot13},
		{NULL, NULL}};
	int i = 0;
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
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			count += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (count);
}