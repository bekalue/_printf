#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *print_rot - traduce letras a rot13
 *@c: string
 *Return: i which is the counter of characters
 **/
int print_rot(va_list c)
{
    int i = 0;
    char *str;

    str = va_arg(c, char *);

    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
            {
                _putchar(str[i] + 13);
            }
            else
            {
                _putchar(str[i] - 13);
            }
        }
        else
        {
            _putchar(str[i]);
        }
        i++;
    }
    return (i);
}

/**
 * print_rev - str
 *@ch: char
 *Return: lenght
 **/
int print_rev(va_list ch)
{
    char *cadena;
    int i = 0, cont = 0;

    cadena = va_arg(ch, char *);
    if (cadena != NULL)
    {
        if (cadena[0] == '\0')
            return (0);

        while (cadena[i] != '\0')
            i++;

        cont = i;

        for (i--; i >= 0; i--)
            _putchar(cadena[i]);
    }
    else
        return (0);
    return (cont);
}
/**
 *rec_bin - str
 *@num: char
 */
void rec_bin(unsigned int num)
{
    if (num / 2)
    {
        rec_bin(num / 2);
        _putchar(num % 2 + '0');
    }
    else
        _putchar(num % 2 + '0');
}

/**
 *print_binary - str
 * *@c: c
 * *Return: lenght
 * **/
int print_binary(va_list c)
{
    unsigned int num;
    int iter;

    num = va_arg(c, unsigned int);
    rec_bin(num);
    for (iter = 0; num / 2; iter++)
        num = num / 2;
    return (iter + 1);
}