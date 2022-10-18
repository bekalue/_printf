#include "main.h"

/**
 * number_printf - prints an integer
 * @arg: integer to print
 *
 * Return: length
 */
int number_printf(va_list arg)
{
    int num = va_arg(arg, int);
    unsigned int counter = 0, unsnum;
    int i = 0;
    char aski[10];

    if (num < 0)
    {
        _putchar('-');
        counter++;
        unsnum = -num;
    }
    else
        unsnum = num;
    if (unsnum > 0)
    {
        while (unsnum != 0)
        {
            aski[i] = (unsnum % 10) + '0';
            unsnum /= 10;
            i++;
        }
        i--;
        while (i >= 0)
        {
            _putchar(aski[i]);
            i--;
            counter++;
        }
    }
    else
    {
        _putchar('0');
        counter++;
    }
    return (counter);
}