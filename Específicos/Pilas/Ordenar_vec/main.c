#include <stdio.h>
#include <stdlib.h>
#include "piladingen.h"

int main()
{
    int vec[10] = { 22, 12, 34, 1, 2, 99, 76, 25, 10, 7};
    int i, tope;
    t_pila pila;

    crearPila(&pila, sizeof(int));

    for (i = 0; i < 10; i++)
        apilar(&pila, &vec[i]);

    ordenarPila(&pila, compararEnteros);

    for (i = 0; i < 10; i++)
        desapilar(&pila, &vec[i]);

    for (i = 0; i < 10; i++)
        printf("%d \n", vec[i]);

    return 0;
}
