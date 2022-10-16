#include "main.h"


/**
 * _printf - prints a formatted output to the stdout and returns the length of output
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	print_f print[] = {
		{"s", print_string},
		{"c", print_char},
		{"%", print_percentage},
		{NULL, NULL}};

	va_list args;
	unsigned int count = 0, i, j;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; print[j].s[0]; j++)
			{
				if (print[j].s[0] == format[i + 1])
				{
					count += print[j].f(args);
					i++;
					break;
				}
				if (print[j + 1].s == NULL)
				{
					if (format[i + 1] > 32 && format[i + 1] < 127)
					{
						count++, _putchar(format[i]);
						break;
					}
					else
						return (-1);
				}
			}
			if (format[i + 1] != '\0')
			{
				i++;
				continue;
			}
			else
				break;
		}
		_putchar(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}
