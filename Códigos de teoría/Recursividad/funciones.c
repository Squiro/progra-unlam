#include "funciones.h"

/** Ejemplo de recursividad con factorial */

double factorial(int numero)
{
    if (numero)
        return numero * factorial(numero-1);
    else
        return 1;
}

/* Mostrar una cadena, recorriendo un caracter por linea

*   *   *   *   hola    a       hola    hola  /!\  hola    h
h   a   h   h   ola     la      ola     ola        hol     ho
o   l   o   o   la      ola     la      la         ho      ho
l   o   l   l   a       hola    a       a          h       hola
a   h   a   a                   a       la
*   *   a   l                   la      ola
        l   o                   ola     hola
        o   h                   hola
        h   *
        *
*/

/* Resuelve el primer hola */

void mostrarPorLinea(const char * str)
{

    if (!(*str))
        return;
    printf("%c\n", *str);
    mostrarPorLinea(str+1);
}

/* Resuelve el segundo hola */

void mostrarPorLineaInverso(const char * str)
{
    if (!(*str))
        return;
    mostrarPorLineaInverso(str+1);
    printf("%c\n", *str);
}

void mostrarPorLineaAmbos(const char * str)
{
    if (!(*str))
        return;

    printf("%c\n", *str);
    mostrarPorLineaAmbos(str+1);
    printf("%c\n", *str);
}

/* Resuelve el tercer hola */

void mostrarPorLineaAmbosSinDP(const char * str)
{
    printf("%c\n", *str);

    if (!(*(str+1)))
        return;

    mostrarPorLineaAmbosSinDP(str+1);
    printf("%c\n", *str);
}

/* Resuelve... dios ya sabes que va en orden */

void mostrarCadenaDecreciente(const char * str)
{
    if (!(*str))
        return;

    printf("%s\n", str);
    mostrarCadenaDecreciente(str+1);
}

void mostrarCadenaCreciente(const char * str)
{
    if (!(*(str)))
        return;
    mostrarCadenaCreciente(str+1);
    printf("%s\n", str);
}

void mostrarCadenaAmbos(const char * str)
{
    if (!(*str))
        return;

    printf("%s\n", str);
    mostrarCadenaAmbos(str+1);
    printf("%s\n", str);
}

void mostrarCadenaAmbosSinDP(const char * str)
{
    printf("%s\n", str);

    if (!(*(str+1)))
        return;

    mostrarCadenaAmbosSinDP(str+1);
    printf("%s\n", str);
}

void mostrarPrinDecreciente(const char * str)
{
    printf("%c", *str);
}

/*

N° 1234

*   *   1234    1    /!\   1234
1   4   123     12         234
2   3   12      123        34
3   2   1       1234       4
4   1
*   *

*/

void mostrarNumeroPorLinea(const int num)
{
    if(num < 1)
        return;
    mostrarNumeroPorLinea(num/10);
    printf("%d\n", num%10);
}

void mostrarNumeroPorLineaInverso(const int num)
{
    if(num < 1)
        return;
    printf("%d\n", num%10);
    mostrarNumeroPorLineaInverso(num/10);
}

void mostrarNumeroEscalonado(const int num)
{
    if(num < 1)
        return;
    printf("%d\n", num);
    mostrarNumeroEscalonado(num/10);
}

void mostrarNumeroEscalonadoInverso(const int num)
{
    if(num < 1)
        return;
    mostrarNumeroEscalonadoInverso(num/10);
    printf("%d\n", num);
}

void mostrarNumeroAmbos(const int num)
{
    if(num < 1)
        return;

    printf("%d\n", num);
    mostrarNumeroAmbos(num/10);
    printf("%d\n", num);
}

void mostrarNumeroAmbosSinDP(const int num)
{
    printf("%d\n", num);

    if((num/10) < 1)
        return;

    mostrarNumeroAmbosSinDP(num/10);
    printf("%d\n", num);
}

/*void mostrarNumeroDificil(const int num, int divisor)
{
    if(num < 1)
        return;

    printf("%d\n", num/divisor);
    mostrarNumeroDificil(num, divisor/10);
}*/

/*
Mostrar una lista simplemente enlazada en orden inverso

//Mostrar esto
(4, '*')

****    *
***     **
**      ***
*       ****

*/

