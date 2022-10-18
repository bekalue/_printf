#include "main.h"

/**
 * _pwr - Does exponential arithmetic
 * @a: Base number
 * @b: exponential number
 * Return: Result
 */
int _pwr(int a, int b)
{
    int result = 1;

    for (; b > 0; b--)
    {
        result = result * a;
    }
    return (result);
}