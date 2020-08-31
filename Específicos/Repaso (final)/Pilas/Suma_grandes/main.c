#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "funciones.h"

int main()
{
    char *num1, *num2;
    t_pila pila1, pila2, pila3;
    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pila3);

    num1 = leerNum("num1.txt");
    num2 = leerNum("num2.txt");
    guardarEnPila(&pila1, num1);
    guardarEnPila(&pila2, num2);
    sumarPilas(&pila1, &pila2, &pila3);

    printf("SUMA: %s", stackToStr(&pila3));

    return 0;
}
