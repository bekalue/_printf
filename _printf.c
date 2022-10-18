#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - function that prints messages on the screen using a format
 * @format: a string given
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, count = 0;
	int (*ptr)(va_list);

	va_start(list, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (format[i + 1] != '\0')
			{
				ptr = get_func(format[i + 1]);
				count += ptr(list);
				i++;
			}
			else
			{
				return (-1);
			}
		}
		else if (format[i] == '%' && format[i] == '%')
		{
			_putchar(format[i]);
			i++;
			count++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(list);
	return (count);
}
