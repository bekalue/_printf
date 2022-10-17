#include "main.h"

/**
 * determine_function - determines a function depending on the type
 * of specifier passed
 * @format: a specifier.
 * Return: a right(choosen) function
 */
int (*determine_function(const char *format))(va_list)
{
	unsigned int i;
	print_f func[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_num},
		{"d", print_num},
		{"u", print_unsigned_int},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_heXadecimal},
		{"p", print_address},
		{"S", print_String},
		{"r", print_reversed},
		{"R", print_rot13},
		{NULL, NULL}};
	for (i = 0; func[i].s != NULL; i++)
	{
		if ((*func[i].s) == *format)
			return (func[i].f);
	}
	return (NULL);
}

/**
 * _printf - prints formatted string just like printf
 * @format: a pointer to a string.
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*f)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	i = 0;
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		if (!format[i + 1])
			return (count);
		f = determine_function(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args);
			i += 2;
			continue;
		}
		_putchar(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}
