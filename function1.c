#include "main.h"

/*functions*/

/*PRINT_CHAR*/
/**
 *print_char - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list ch)
{
    char a = va_arg(ch, int);

    _putchar(a);
    return (1);
}

/*PRINT_STRING*/
/**
 *print_string - print pointers
 *@s:receive pointer
 *Return: 1;
 */
int print_string(va_list s)
{
    char *str = va_arg(s, char *);
    int i, j;
    int count = 0;
    char *null = "(null)";

    if (str != NULL)
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            _putchar(str[i]), count++;
        }
    }
    else if (str == NULL)
    {
        for (j = 0; null[j] != '\0'; j++)
        {
            _putchar(null[j]);
        }
        count = 6;
    }

    return (count);
}

/**
 *print_number - print a int
 *@i: receive int number
 *Return: number of characters
 */

int print_number(va_list i)
{
    int count = 0;
    int n = va_arg(i, int);
    unsigned int dc, dig, nat = n;
    double f = 1;

    if (n == 0)
        _putchar('0'), count++;
    else
    {
        if (n < 0)
        {
            nat = n * -1;
            _putchar('-'), count++;
        }

        while (f <= nat)
            f *= 10;
        dc = f / 10;

        while (dc >= 1)
        {
            dig = nat / dc;
            _putchar(dig + '0'), count++;
            nat = (nat - (dc * dig));
            dc /= 10;
        }
    }
    return (count);
}

/*PRINT UNSIGNED INT*/
/**
 *print_number_ui - in this case only return negative numbers
 *@i: receive int number
 *Return: number of characters
 */
int print_number_ui(va_list i)
{
    int count = 0;
    int n = va_arg(i, int);
    unsigned int dc, dig, nat = n;
    double f = 1;

    if (n == 0)
        _putchar('0');
    else
    {
        while (f <= nat)
            f *= 10;

        dc = f / 10;

        while (dc >= 1)
        {
            dig = nat / dc;
            _putchar(dig + '0');
            nat = (nat - (dc * dig));
            dc /= 10;
            count++;
        }
    }
    return (count);
}

/**
 *print_Binary - normal - print a number
 *@b: receive a number int
 *Return: num of characters
 */
int print_Binary(va_list b)
{
    unsigned int i, aux = 0;

    char *str;
    int n = 0;
    int m;

    i = va_arg(b, unsigned int);
    m = i;
    while (i > 0)
    {
        aux++;
        i /= 2;
    }

    str = malloc(aux * (sizeof(int) + 1));

    while (m > 0)
    {
        str[n] = (m % 2) + '0';
        n++;
        m /= 2;
    }
    while (n >= 0)
        _putchar(str[n]), n--;
    free(str);
    return (aux);
}
