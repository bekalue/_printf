#include "main.h"
/**
 * _printf - prints a string to stdout
 * @format: string to print
 * Return: number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, cn = 0;
	int (*fnpointer)(va_list);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(list, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			fnpointer = print_sel(format[i + 1]);
			cn += fnpointer(list);
			i++;
		}
		else
		{
			_putchar(format[i]);
			cn++;
		}
	}
	va_end(list);
	return (cn);
}