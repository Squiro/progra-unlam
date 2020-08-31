#include "funciones.h"

char * mi_itoa(int num, int base)
{
    int size = 256, count = 0, signo = 0, resto;
    char * str = (char *) malloc(sizeof(char)*256);
    char *pIni = str;

    if (num < 0 && base == 10)
    {
        signo = 1;
        num *= -1;
    }

    while (num != 0)
    {
        resto = num % base;
        num = num/base;

        if (count >= size-1)
        {
            size *= 2;
            str = (char *) realloc(str, size);
            if (!str)
            {
                fprintf(stderr, "Sin memoria");
                exit(1);
            }
        }

        *str = (resto > 9) ? resto-10 + 'a' : resto + '0';
        str++;
        count++;
    }

    if (signo)
        *(str++) = '-';

    *str = '\0';

    return invertirCadena(pIni);
}

int mi_strlen(const char * str)
{
    int count = 0;

    while (*str)
    {
        str++;
        count++;
    }

    return count;
}

char * invertirCadena(char * str)
{
    char *pIni = str;
    char *pFin = pIni + mi_strlen(pIni)-1;
    char aux;

    while (pFin > pIni)
    {
        aux = *pFin;
        *pFin = *pIni;
        *pIni = aux;
        pFin--;
        pIni++;
    }
    return str;
}
