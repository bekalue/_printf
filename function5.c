#include "main.h"
/**
 * print_sel - function pointer to functions
 * @idsel: char to compare
 * Return: function used and counter
 */
int (*print_sel(char idsel))(va_list)
{
    id fnarray[] = {
        {"c", _print_c},
        {"s", _print_s},
        {"%", _print_mod},
        {"d", _print_i},
        {"i", _print_i},
        {"u", _print_ui},
        {"b", _print_b},
        {"o", _print_o},
        {'\0', NULL}};

    int j;

    for (j = 0; fnarray[j].argument != NULL; j++)
    {
        if (idsel == *fnarray[j].argument)
        {
            return (fnarray[j].f);
        }
    }
    _putchar('%');
    _putchar(idsel);
    return (fn_unk);
}