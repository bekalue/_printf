#include "main.h"
#define BUFFER_SIZE 1024
/**
 * _count - Count the characters
 * @list: list
 * Return: Number of characters
 */
int _count(va_list list)
{
	int count = 0;
	(void)list;

	count++;
	count++;

	return (count);
}

/**
 * get_func - function
 * @func: format
 * Return: contador
 */
int (*get_func(char func))(va_list list)
{
	int i = 0;

	op_t op[] = {
		{"c", _printf_c},
		{"s", _printf_s},
		{"d", _printf_d_i},
		{"i", _printf_d_i},
		{"u", _printf_u},
		{"r", _printf_r},
		{"R", _printf_13},
		{"\0", NULL}};
	for (i = 0; *op[i].func != '\0'; i++)
	{
		if (func == *op[i].func)
		{
			return (op[i].f);
		}
	}
	_putchar('%');
	_putchar(func);
	return (_count);
}
