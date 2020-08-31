#include <stdio.h>
#include <stdlib.h>

int main()
{
    //rand() genera desde [0; MAXRAND]
    //rand() % 7 + genera numeros desde [0;6]
    /*
    Si quiero generar desde [-43;37]

    rand() % 81 - 43 genera enre [0;80]
    Si me da 0 y le resto 43, me queda -43
    Si me da 81 y le resto 43, me queda 37
    Entonces me cumplo con el rango requerido

    */

    //rand() utiliza siempre la misma semilla, generando numeros pseudoaleatorios
    //srand() cambia la semilla que estamos usando, para asi generar numeros aleatorios
    printf("Hello world!\n");

    /*
    Usamos vectores para generar aleatoriamente ciertos numeros

    int vec[3] = { 325, 842, 1043 };
    vec[rand()%3]

    */
    return 0;
}
