#include <stdio.h>
#include <stdlib.h>
#include "pilaest_gen.h"

int main()
{
    //t_pila pila = { sizeof(int) };
    t_pila pila;
    crearPila(&pila, sizeof(int));
    printf("Hello world!\n");
    return 0;
}
