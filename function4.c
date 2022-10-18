#include "main.h"

/**
 * unsigned_printf - prints an unsigned integer
 * @u: integer to print
 *
 * Return: length
 */
int unsigned_printf(va_list u)
{
    unsigned int integer, y, x;
    int num, len;

    num = va_arg(u, int);

    integer = num;
    y = integer;
    x = 1;

    while (y > 9)
    {
        y /= 10;
        x *= 10;
    }
    for (; x >= 1; x /= 10)
    {
        len += _putchar(((integer / x) % 10) + '0');
    }
    return (len);
}