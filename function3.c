#include "main.h"

/**
 * _print_b - prints binary number
 * @list: int from list
 * Return: counter
 */
int _print_b(va_list list)
{
    int digit, i = 0, cn = 0;
    unsigned int num = va_arg(list, int);
    unsigned int n = num;
    char *str;

    if (!n)
    {
        _putchar('0');
        return (1);
    }

    while (n != 0)
    {
        n /= 2;
        digit++;
    }

    n = num;
    str = malloc((sizeof(int) * digit) + 1);

    if (str == NULL)
        return (-1);

    while (n > 0)
    {
        str[i] = n % 2;
        n /= 2;
        i++;
    }

    while (i != 0)
    {
        i--;
        _putchar(str[i] + '0');
        cn++;
    }

    free(str);
    return (cn);
}
/**
 * _print_o - prints octal number
 * @list: int from list
 * Return: counter
 */
int _print_o(va_list list)
{
    int digit, i = 0, cn = 0;
    unsigned int num = va_arg(list, int);
    unsigned int n = num;
    char *str;

    if (!n)
    {
        _putchar('0');
        return (1);
    }

    while (n != 0)
    {
        n /= 8;
        digit++;
    }

    n = num;
    str = malloc((sizeof(int) * digit) + 1);

    if (str == NULL)
        return (-1);

    while (n > 0)
    {
        str[i] = n % 8;
        n /= 8;
        i++;
    }

    while (i != 0)
    {
        i--;
        _putchar(str[i] + '0');
        cn++;
    }

    free(str);
    return (cn);
}