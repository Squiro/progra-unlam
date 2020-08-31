#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int x = 1, i;
    t_lista lista;

    crearLista(&lista);

    for (i = 0; i < 9; i++)
        insertarOrdenado(&lista, &i, compararEnteros);

    recorrerLista(&lista);
    /*ordenarLista(&lista, compararEnteros);
    recorrerLista(&lista);*/

    return 0;
}
