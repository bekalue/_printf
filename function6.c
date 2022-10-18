#include "main.h"

/**
 * pointer_printf - prints a pointer's adress
 * @p: pointer
 *
 * Return: pointer
 */

int pointer_printf(va_list p)
{
    char *str;
    int i = 0;

    str = va_arg(p, char *);
    if (str == NULL)
    {
        return (0);
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
    }

    return (i);
}