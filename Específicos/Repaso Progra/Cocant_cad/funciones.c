#include "funciones.h"

char * strcat_inverso(char * cad1, char * cad2)
{
    char * pIni = cad1;
    int len = mi_strlen(cad2);

    while (*cad1)
        cad1++;

    while (cad1 >= pIni)
    {
        *(cad1+len) = *cad1;
        cad1--;
    }

    cad1 = pIni;

    while (*cad2)
    {
        *cad1 = *cad2;
        cad1++;
        cad2++;
    }

    return pIni;
}

int mi_strlen(char * str)
{
    int i = 0;
    while (*str)
    {
        i++;
        str++;
    }

    return i;
}
