#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main()
{
    t_lista lista;
    int i;

    crearLista(&lista);
    for (i = 0; i < 9 ; i++)
        insertarPrincipio(&lista, &i);

    mostrarLista(&lista);
    ordenarLista(&lista, compararEnteros);
    mostrarLista(&lista);

    return 0;
}
