#include "main.h"

/**
 *_printf_c - funcion que corresponde a printf %c
 *@list: va_list
 *caracter-> caracter a printear perteneciente a la tabla ASCII
 *Return: 1
 */

int _printf_c(va_list list)
{
	char caracter;

	caracter = va_arg(list, int);
	return (write(1, &caracter, 1));
}

/**
 *_printf_s - function that prints a string
 *@list: va_list
 *str-> string to print
 *Return: i
 */
int _printf_s(va_list list)
{
	char *str = va_arg(list, char *);
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*(str + i) != 0)
	{
		_putchar(*(str + i));
		i++;
	}
	return (i);
}

/**
 *_printf_d_i - function that prints an integer.
 *
 *n-> number given.
 *@list: va_list
 *Return: i
 */
int _printf_d_i(va_list list)
{
	long int n = va_arg(list, int);
	unsigned int dc, dig, nat = n;
	double f = 1;
	int count = 0;

	if (!n)
		n = '\0';
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	else
	{
		if (n < 0)
		{
			nat = n * -1;
			_putchar('-');
			count++;
		}
		while (f <= nat)
			f *= 10;
		dc = f / 10;
		while (dc >= 1)
		{
			dig = nat / dc;
			count += _putchar(dig + '0');
			nat = (nat - (dc * dig));
			dc /= 10;
		}
	}
	return (count);
}

/**
 * _printf_u - function that prints an unsigned integer
 * n-> number
 * @list: va_list
 * Return: i
 */
int _printf_u(va_list list)
{
	unsigned int n = va_arg(list, unsigned int);
	int count = 0;
	unsigned int dc, dig, nat = n;
	double f = 1;

	if (!n)
		n = '\0';

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (f <= nat)
			f *= 10;
		dc = f / 10;
		while (dc >= 1)
		{
			dig = nat / dc;
			count += _putchar(dig + '0');
			nat = (nat - (dc * dig));
			dc /= 10;
		}
	}
	return (count);
}

/**
 * _printf_r - function that prints a string in reverse
 * str-> pointer
 * @list: va_list
 * Return: a
 */
int _printf_r(va_list list)
{
	char *str = va_arg(list, char *);
	int a = 0;
	int b;

	if (!str)
		str = "(null)";

	while (*str != '\0')
	{
		a++;
		++str;
	}
	str--;
	for (b = a; b > 0; b--)
	{
		_putchar(*str);
		str--;
	}
	return (a);
}
