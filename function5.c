#include "main.h"

/**
 * rot13_printf - encodes a string into ROT13
 * @arg: string adress
 * Return: int
 */
int rot13_printf(va_list arg)
{
    int i, j, counter = 0;
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char b[] = "NOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM";
    char *s = va_arg(arg, char *);

    if (s == NULL)
        s = "(NULL)";
    for (i = 0; s[i]; i++)
    {
        for (j = 0; j < 52; j++)
        {
            if (s[i] == a[j])
                break;
        }
        if (s[i] == a[j])
        {
            _putchar(b[j]);
            counter++;
        }
        else
        {
            _putchar(s[i]);
            counter++;
        }
    }
    return (counter);
}
