#include "funciones.h"

char * subcadena(char *str1, char *str2)
{
    char * pIni, * pIni2 = str2;

    while (*str1)
    {
        pIni = str1;
        while (*str2 && *str1 == *str2)
        {
            str1++;
            str2++;
        }

        if (!(*str2))
            return pIni;

        str2 = pIni2;
        str1 = pIni;
        str1++;
    }

    return NULL;
}

int eliminarCaracteres(char * str1, char *str2)
{
    char * pIni = str2;
    int count = 0;

    while (*str1)
    {
        while (*str2)
        {
            if (*str1 == *str2)
            {
                *str1 = ' ';
                count++;
            }
            str2++;
        }

        str2 = pIni;
        str1++;
    }

    return count;
}
