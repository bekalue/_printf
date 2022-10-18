#include "main.h"

/**
 * fn_unk - counter for unknown identifier
 * @list: args
 * Return: counter
 */
int fn_unk(va_list list)
{
    int count = 0;
    (void)list;

    count++;
    count++;

    return (count);
}