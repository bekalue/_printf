#include "main.h"

/**
 * get_func - determines function based up on the specifier passed.
 * @specifier: a specifier passed.
 *
 * Return: the choosen function or null.
 */

int (*get_func(const char *specifier))(va_list)
{
	print_f func[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_num},
		{"i", print_num},
		{"u", print_unsigned_int},
		{"R", print_rot13},
		{"r", print_reversed},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_heXadecimal},
		{"p", print_address},
		{NULL, NULL}
	};

	unsigned int i;

	i = 0;
	while (i != 13) /*13 is the size of func which array of structs*/
	{
		if ((*func[i].s) == (*specifier))
		return (func[i].f);
		i++;
	}
	return (NULL);
}
/**
 * verify - validates the specifier.
 * @specifier: a specifier.
 * Return: not verified (0) or verified (1).
 */
int verify(const char *specifier)
{
	char *str = "csdiRurboxXp";
	int len;
	int i;

	len = strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == (*specifier))
		return (1);
		i++;
	}
	return (0);
}
/**
 * _printf - print whatever is given
 * @format: arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arguments;
	unsigned int count = 0, i;
	int (*f)(va_list);

	va_start(arguments, format);

	if (format != NULL)
	{
		for (i = 0; format[i]; i++)
		{
			if (format[i] == '%' && format[i + 1] != '%' && format[i + 1] != '%')
			{
				if (verify(&format[i + 1]) == 1)
				{
					f = (*get_func(&format[i + 1]));
					count += f(arguments);
					i++;
				}
				else
				_putchar(format[i]), count++;
			}
			else if (format[i] == '%' && format[i + 1] == '%')
			_putchar('%'), i++, count++;
			else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
			else
			_putchar(format[i]), count++;
		}
	}
	else
	return (-1);

	va_end(arguments);
	return (count);
}
