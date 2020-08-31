#include "funciones.h"

int mi_strlen(char * str)
{
    int len = 0;

    while (*str)
    {
        str++;
        len++;
    }

    return len;
}

//Invierte una cadena de principio a fin normalmente.
char * invertirCadena(char * str)
{
    int i, len = mi_strlen(str);
    char *pIni = str, *pFin = str+len-1;
    char aux;

    for (i = 0; i < len/2; i++, pFin--)
    {
        aux = *str;
        *str = *pFin;
        *pFin = aux;
        str++;
    }

    return pIni;
}

char * invertirInSitu(char * str)
{
    int len = mi_strlen(str);
    char *pIni = str, *pAux;

    while (len > 0)
    {
        pAux = str;

        while (*str && *str != ' ')
        {
            str++;
            len--;
        }

        *str = '\0';
        invertirCadena(pAux);
        *str = ' ';
        str++;
        len--;
    }

    *str = '\0';
    return pIni;
}

char * codificarCadena(char * str)
{
    char *pIni = str;
    char arr[] = "aeiouAEIOU";

    while (*str)
    {
        *str = verificarCaracter(*str, arr);


        /*switch (*str)
        {
          case 'a':
              *str = '0';
              break;
          case 'e':
              *str = '1';
              break;
          case 'i':
              *str = '2';
              break;
          case 'o':
              *str = '3';
              break;
          case 'u':
              *str = '4';
              break;
          case 'A':
              *str = '5';
              break;
          case 'E':
              *str = '6';
              break;
          case 'I':
              *str = '7';
              break;
          case 'O':
              *str = '8';
              break;
          case 'U':
              *str = '9';
              break;
        }*/
        str++;
    }

    return pIni;
}

char * codificarInvertir (char * str)
{
    return invertirInSitu(codificarCadena(str));
}

char verificarCaracter(const char str, char * arr)
{
    int i = 0;

    while (*arr)
    {
        if (str == *arr)
            return '0' + i;
        i++;
        arr++;
    }

    return str;
}
