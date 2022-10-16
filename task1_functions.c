#include "main.h"

/**
 * print_string - prints out a string
 * @args: list of arguments
 *
 * Return: amount of chars printed
 */
int print_string(va_list args)
{
	char *str;
	unsigned int i = 0;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_char - prints out a char
 * @args: char to print
 *
 * Return: amount of chars printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
/**
 * print_percentage - prints out a percetange
 * @args: list of arguments
 *
 * Return: the number of char printed (1)
 */
int print_percentage(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
