#include "main.h"

/**
 * c_printf - Prints a character
 * @arg: Character
 *
 * Return: 1
 */
int c_printf(va_list arg)
{
    char c = va_arg(arg, int);

    return (_putchar(c));
}

/**
 * s_printf - prints a string
 * @arg: string to print
 *
 * Return: length of string
 */

int s_printf(va_list arg)
{
    char *str;
    int i = 0;

    str = va_arg(arg, char *);
    if (str == NULL)
    {
        str = "(null)";
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
    }

    return (i);
}