#include "funciones.h"

int eliminarCaracteres(char * str, char caracter)
{
    int count = 0;

    while (*str)
    {
        if (*str == caracter)
        {
            count++;
            *str = ' ';
        }
        str++;

    }

    return count;
}
