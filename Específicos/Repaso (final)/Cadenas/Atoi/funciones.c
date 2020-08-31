#include "funciones.h"

int mi_atoi(const char *str)
{
    int sgn = 1, res = 0;

    if (*str == '-')
    {
        sgn = -1;
        str++;
    }

    while (*str)
    {
        res = num * 10 + (*str-'0');
        str++;
    }

    return num*sgn;
}
