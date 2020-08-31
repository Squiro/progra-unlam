#include <stdio.h>
#include <stdlib.h>

//Pasaje de parametros
void intercambio(int, int);
void intercambioD(int *, int *);
void intercambioDOK(int *, int *);

int main()
{
    int x = 2, y = 8;
    printf("X: %d, Y: %d\n", x, y);
    intercambioDOK(&x, &y); //Le paso la direccion
    printf("IntercambioDir X: %d, Y: %d\n", x, y);
    return 0;
}

void intercambio(int x, int y)
{
    int aux = x;
    x = y;
    y = aux;
}

void intercambioD(int *x, int *y)
{
    int *aux;
    aux = x;
    x = y;
    y = aux;
}

void intercambioDOK(int *x, int *y)
{
    int aux;
    aux = *x; //Asignamos aux con el contenido de la direccion que recibimos
    *x = *y;
    *y = aux;
}
