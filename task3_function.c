#include "main.h"
/**
 * print_octal - takes an unsigned int and prints it in octal notation
 * @o: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_octal(va_list o)
{
    unsigned int a[11];
    unsigned int i, m, n, sum;
    int count;

    n = va_arg(o, unsigned int);
    m = 1073741824; /* (8 ^ 10) */
    a[0] = n / m;
    for (i = 1; i < 11; i++)
    {
        m /= 8;
        a[i] = (n / m) % 8;
    }
    for (i = 0, sum = 0, count = 0; i < 11; i++)
    {
        sum += a[i];
        if (sum || i == 10)
        {
            _putchar('0' + a[i]);
            count++;
        }
    }
    return (count);
}
/**
 * print_unsigned_int - prints an unsigned in in decimal notation
 * @u: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_unsigned_int(va_list u)
{
    unsigned int a[10];
    unsigned int i, m, n, sum;
    int count;

    n = va_arg(u, unsigned int);
    m = 1000000000; /* (10 ^ 9) */
    a[0] = n / m;
    for (i = 1; i < 10; i++)
    {
        m /= 10;
        a[i] = (n / m) % 10;
    }
    for (i = 0, sum = 0, count = 0; i < 10; i++)
    {
        sum += a[i];
        if (sum || i == 9)
        {
            _putchar('0' + a[i]);
            count++;
        }
    }
    return (count);
}
/**
 * print_hex - prints an unsigned int in hexidecimal form
 * @n: unsigned int to print
 * @c: flag to determine case of printing (0 = lower, 1 = upper)
 *
 * Return: number of digits printed
 */
int print_hex(unsigned int n, unsigned int c)
{
    unsigned int a[8];
    unsigned int i, m, sum;
    char diff;
    int count;

    m = 268435456; /* (16 ^ 7) */
    if (c)
        diff = 'A' - ':';
    else
        diff = 'a' - ':';
    a[0] = n / m;
    for (i = 1; i < 8; i++)
    {
        m /= 16;
        a[i] = (n / m) % 16;
    }
    for (i = 0, sum = 0, count = 0; i < 8; i++)
    {
        sum += a[i];
        if (sum || i == 7)
        {
            if (a[i] < 10)
                _putchar('0' + a[i]);
            else
                _putchar('0' + diff + a[i]);
            count++;
        }
    }
    return (count);
}
/**
 * print_hexadecimal - takes an unsigned int and prints it in lowercase hex notation
 * @x: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_hexadecimal(va_list x)
{
    return (print_hex(va_arg(x, unsigned int), 0));
}

/**
 * print_heXadecimal - takes am unsigned int and prints it in uppercase hex notation
 * @X: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_heXadecimal(va_list X)
{
    return (print_hex(va_arg(X, unsigned int), 1));
}
