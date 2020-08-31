#include "piladingen.h"

int main()
{
    //t_pila pila = { sizeof(int), NULL };
    int x = 10, tope;

    crearPila(&pila, sizeof(int));
    apilar(&pila, &x);
    verTope(&pila, &tope);
    printf("El tope es: %d", tope);
    return 0;
}
