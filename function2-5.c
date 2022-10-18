#include "main.h"

/**
 * _printf_13 - function that prints the rot13'ed string
 * @list: va_list
 * let-> abecedario ordenado, rot->  a rot13
 * p-> puntero
 * Return: contador
 */
int _printf_13(va_list list)
{
	char *p = va_arg(list, char *);

	unsigned int i = 0, c = 0;
	unsigned int j = 0;
	char let[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char rot[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};

	if (p == NULL)
		p = "(nill)";

	while (p[i] != '\0')
	{
		while (let[j] != '\0')
		{
			if (let[j] == p[i])
			{
				_putchar(rot[j]);
				c++;
				break;
			}
			j++;
		}
		if (let[j] == '\0')
		{
			_putchar(p[i]);
			c++;
		}
		i++;
	}
	return (i);
}
