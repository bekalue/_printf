#include "main.h"

/**
 * _print_i - prints decimals and integers
 * @list: arg from list
 * Return: counter
 */
int _print_i(va_list list)
{
    int cn = 0, digit = 0, a = 1;
    unsigned int j;
    int i = va_arg(list, int);

    if (i == 0 || i == '\0')
        return (_putchar('0'));

    if (i < 0)
    {
        _putchar('-');
        cn++;
        i = i * -1;
        j = i;
    }
    else
    {
        j = i;
    }
    while (i != 0)
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