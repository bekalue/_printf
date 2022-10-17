#include "main.h"

/**
 * find_function - determines the type of format passed
 * @format: function
 * Return: Null
 */
int (*find_function(const char *format))(va_list)
{
	print_f find[] ={
		{"c", print_char},
		{"s", print_string},
		{"%", print_percentage},
		{"d", print_decimal},
		{"i", print_integer},
		{NULL, NULL}
	};
	unsigned int i;

	for(i = 0; find[i].s; i++)
	{
		if (find[i].s[0] == (*format))
			return (find[i].f);
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
