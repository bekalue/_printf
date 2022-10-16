#include "main.h"


/**
 * _printf - prints a formated output to the stdout and returns the length of output
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	print_f func_arr[] = {
		{'s', print_string},
		{'c', print_char},
		{'%', print_percent}
	};

	unsigned int count = 0, i, j;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func_arr[j]; j++)
			{
				if (func_arr[j].s == format[i + 1])
				{
					count += func_arr[j].f(arguments);
					i++;
					break;
				}
			}
		}
		count++;
		_putchar(format[i]);
	}
	va_end(arguments);
	return (count);
}
