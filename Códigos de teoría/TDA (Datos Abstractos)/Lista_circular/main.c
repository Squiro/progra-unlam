#include <stdio.h>
#include <stdlib.h>
#include "lista_circ.h"

//Una lista circular apunta siempre al primer elemento de la lista.
//Si una lista tiene un unico elemento, apunta a si mismo.

/*

    Pila circular:

    La pila apunta a A (el ultimo de la pila), y utilizo el siguiente de A como forma para seleccionar al primero (el que fue ingresado primero). O sea, A es
    un intermediario. Si quiero sacar al ultimo, saco al sig de A, y cambio este mismo siguiente al siguiente del ultimo.
    Si quiero añadir un nodo, le pongo al nuevo->sig la dir del A->sig, y listo.

    Cola circular:

    Utilizo el primero de la cola (ultimo en ser agregado) como intermediario. El siguiente del primero apunta al ultimo.
    El ultimo apunta al siguiente.

*/

int main()
{
    int i, y = 0;
    t_lista pilaCirc, colaCirc;

    /*crearPila(&pilaCirc);
    for (i = 0; i < 10; i++)
        apilar(&pilaCirc, &i);

    desapilar(&pilaCirc, &y);
    printf("DESAPILAR: %d\n", y);
    verTopePila(&pilaCirc, &y);
    printf("TOPE: %d\n", y);
    vaciarPila(&pilaCirc);
    y = 0;
    verTopePila(&pilaCirc, &y);
    printf("TOPE: %d\n", y);*/

    crearCola(&colaCirc);

    for (i = 0; i < 10; i++)
        acolar(&colaCirc, &i);
    desacolar(&colaCirc, &y);
    printf("DESACOLAR: %d\n", y);
    verTopeCola(&colaCirc, &y);
    printf("TOPE: %d\n", y);
    vaciarCola(&colaCirc);
    y = 0;
    verTopeCola(&colaCirc, &y);
    printf("TOPE: %d\n", y);
    return 0;
}
