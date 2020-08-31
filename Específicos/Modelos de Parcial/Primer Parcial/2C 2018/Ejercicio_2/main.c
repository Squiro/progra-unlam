#include <stdio.h>
#include <stdlib.h>

int es_palindromo(const char *cad);
char a_mayus(char c);

int main()
{
    printf("Hello world!\n");
    char cadena[] = "Ani ta L avAl aTiNA";
    int res = es_palindromo(cadena);
    if(res)
    {
        printf("Es palíndromo");
    }
    else
    {
        printf("No es palíndromo.");
    }
    return 0;
}

int es_palindromo(const char *cad)
{
    char *p_inicio, *p_fin;
    p_inicio = cad;
    p_fin = cad;

    while(*p_fin != '\0')
    {
        p_fin++;
    }

    p_fin--;

    while(*cad!= '\0')
    {
        while(*cad == ' ' && *cad!= '\0')
            cad++;
        while(*p_fin == ' ' && *p_fin != '\0')
            p_fin--;
        if(a_mayus(*cad) != a_mayus(*p_fin))
        {
            return 0;
        }
        cad++;
        p_fin--;
    }
    return 1;

}

char a_mayus(char c)
{
    return ((c)>='a' && (c)<='z')?(c)-32:c;
}
