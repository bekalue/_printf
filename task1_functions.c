#include "main.h"

/**
 * print_string - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int print_string(va_list arguments)
{
	unsigned int i;
	char *s;

	s = va_arg(arguments, char *);
	if (s == NULL)
	{
		i = _printf("(nill)");
		return (i);
	}
	else
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			{
				_putchar('\\');
				_p('x');
				if (str[i] < 16)
					_stdout('0');
				print_heXadecimaln(str[i]);
				i += 4;
			}
		}
		else
		{
			_printf(s[i]);
		}
			_putchar(s[i]);
	return (i);
}
int print_character(
