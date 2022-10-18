#include "main.h"

/**
 * get__op_func - determines function based up on the specifier passed.
 * @specifier: a specifier passed.
 *
 * Return: the choosen function or null.
 */

int (*get_op_func(char s))(va_list)
{
	int iterarr = 0;
	type_t_f search[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_number},
		{'i', print_number},
		{'u', print_number_ui},
		{'R', print_rot},
		{'r', print_rev},
		{'b', print_binary},
		{'o', print_octal},
		{'x', print_hexa},
		{'X', print_HEXA},
		{'p', print_pointer},
		{'\0', NULL},
	};

	while (iterarr != 13)
	{
		if (search[iterarr].tipo == s)
		{
			return (search[iterarr].f);
		}
		else
		{
			iterarr++;
		}
	}
	return (NULL);
}
/**
 * verify - validates the specifier.
 * @specifier: a specifier.
 * Return: not verified (0) or verified (1).
 */
int verify(char c)
{
	char *cadena = "csdiRurboxXp";
	int t = 11;
	int i = 0;

	while (i <= t)
	{
		if (cadena[i] == c)
		{
			return (1);
		}
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
	int num_characters = 0, iter = 0;
	va_list parameter;

	va_start(parameter, format);

	if (format != NULL)
	{
		for (iter = 0; format[iter]; iter++)
		{
			if (format[iter] == '%' && format[iter + 1] != '%' && format[iter + 1] != '\0')
			{
				if (verify(format[iter + 1]) == 1)
				{
					num_characters += (*get_op_func(format[iter + 1]))(parameter);
					iter++;
					/*continue;*/
				}
				else
					_putchar(format[iter]), num_characters++;
			}
			else if (format[iter] == '%' && format[iter + 1] == '%')
				_putchar('%'), iter++, num_characters++;
			else if (format[iter + 1] == '\0' && format[iter] == '%')
			{
				return (-1);
			}
			else
				_putchar(format[iter]), num_characters++;
		}
	}
	else
		return (-1);

	return (num_characters);
	va_end(parameter);
}