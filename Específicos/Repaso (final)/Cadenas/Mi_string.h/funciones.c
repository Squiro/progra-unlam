#include "funciones.h"

char * strcpy(char *str1, const char *str2)
{
    char * pIni = str1;

    while (*str2)
        *str1++ = *str2++;

    *str1 = '\0';

    return pIni;
}

char * strncpy(char *str1, const char *str2, unsigned int limit)
{
    char * pIni = str1;
    int count = 0;

    while (*str2 && count <= limit)
    {
        *str1++ = *str2++;
        count++;
    }

    *str1 = '\0';

    return pIni;
}

char * strcat(char *str1, const char *str2)
{
    char * pIni = str1;

    while (*str1)
        str1++;

    while (*str2)
        *str1++ = *str2++;


    *str1 = '\0';

    return pIni;
}

char * strncat(char *str1, const char *str2, unsigned int limit)
{
    char * pIni = str1;
    int count = 0;

    while (*str1)
        str1++;

    while (*str2 && count <= limit)
    {
        *str1++ = *str2++;
        count++;
    }

    *str1 = '\0';

    return pIni;
}

int strcmp(const char *str1, const char *str2)
{
    do
    {
        if (*str1 != *str2)
            return *str1 - *str2;
    } while (*str1 && *str2);

    return 0;
}

int strncmp(const char *str1, const char *str2, unsigned int limit)
{
    int count = 0;

    do
    {
        if (*str1 != *str2)
            return *str1 - *str2;
        count++;
    } while (*str1 && *str2 && count <= limit);

    return 0;
}

char * strchar(char * str, int caracter)
{
    while (*str != caracter)
    {
        if (!*str++)
            return NULL;
    }

    return str;
}

char * strrchar(char * str, int caracter)
{
    char * pos = NULL;

    while (*str)
    {
        if (*str == caracter)
            pos = str;
        str++;
    }

    return pos;
}

char * strstr(char *str, char *str2)
{
    int len1 = strlen(str), len2 = strlen(str2), i;

    for (i = 0; i+len2 <= len1; i++)
    {
        if (coinciden(str+i, str2))
            return str+i;
    }

    return NULL;
}

int coinciden(char *str, char *str2)
{
    while (*str2)
        if (*str++ != *str2++)
            return 0;

    return 1;
}

int strlen(const char *str)
{
    int len = 0;

    while (*str)
    {
        str++;
        len++;
    }

    return len;
}
