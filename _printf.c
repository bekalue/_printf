#include "main.h"

/**
 * find_func - determines a function depending on the type and prints
 * of specifier passed
 * @c: a specifier.
 * @args: a list of arguments
 * Return: a right(choosen) function
 */
int find_func(const char *c, va_list args)
{
	int i = 0;
	int len = 0;
	print_f flags[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_num},
		{"i", print_num},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"\n", NULL}};
	while (flags[i].s)
	{
		if ((*flags[i].s) == (*c))
			len = flags[i].f(args);

		i++;
	}
	if ((*c) == '%')
	{
		_putchar('%');
		return (1);
	}
	return (len);
}

/**
 * _printf - prints formatted string just like printf
 * @format: a pointer to a string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int s, count;

	count = 0;
	va_start(args, format);
	for (s = 0; format[s] != '\0'; s++)
	{
		if (format[s] == '%')
		{
			count += find_func(&format[s + 1], args);
			s++;
		}
		else
		{
			_putchar(format[s]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
