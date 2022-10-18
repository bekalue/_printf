#include "main.h"

/**
 * _print_ui - prints unsigned integers
 * @list: int from list below 0
 * Return: counter
 */
int _print_ui(va_list list)
{
    int cn = 0, digit = 0, a = 1;
    unsigned int j;
    unsigned int i = va_arg(list, int);

    j = i;

    while (i > 0)
    {
        i /= 10;
        digit++;
    }
    digit--;
    while (digit > 0)
    {
        a = _pwr(10, digit);
        _putchar((j / a) % 10 + '0');
        cn++;
        digit--;
    }
    _putchar(j % 10 + '0');
    cn++;
    return (cn);
}