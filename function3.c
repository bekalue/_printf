#include "main.h"

/**
 *rec_oct - str
 *@num: char
 */
void rec_oct(unsigned int num)
{
    if (num / 8)
    {
        rec_oct(num / 8);
        _putchar(num % 8 + '0');
    }
    else
        _putchar(num % 8 + '0');
}

/**
 *print_octal - str
 * *@c: c
 * *Return: length
 * **/
int print_octal(va_list c)
{
    unsigned int num;
    long int iter;

    num = va_arg(c, unsigned int);
    rec_oct(num);
    for (iter = 0; num / 8; iter++)
        num = num / 8;
    return (iter + 1);
}

/**
 *rec_hexa - function that gives you the hexa number
 *@num: user given number
 **/
void rec_hexa(unsigned int num)
{
    int dif;

    if (num / 16)
    {
        rec_hexa(num / 16);
        if (num % 16 > 9 && num % 16 <= 16)
        {
            dif = (num % 16) - 9;
            _putchar((dif + 1) + '_');
        }
        else
            _putchar(num % 16 + '0');
    }
    else
    {
        if (num % 16 > 9 && num % 16 < 16)
        {
            dif = (num % 16) - 9;
            _putchar((dif + 1) + '_');
        }
        else
            _putchar(num % 16 + '0');
    }
}
/**
 *print_hexa - function that gives you the hexa number
 *@c: user given number
 *Return: 0
 **/
int print_hexa(va_list c)
{
    long int num;
    unsigned int iter;

    iter = va_arg(c, unsigned int);

    rec_hexa(iter);

    for (num = 0; iter / 16; num++)
    {
        iter = iter / 16;
    }
    return (num + 1);
}
