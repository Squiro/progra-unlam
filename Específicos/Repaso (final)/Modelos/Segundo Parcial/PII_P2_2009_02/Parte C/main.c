#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "lista_circ.h"
#include "funciones.h"

int main()
{
    t_lista lista;
    t_arbol arbol;
    t_indice idx;
    long i;

    crearCola(&lista);
    crearArbol(&arbol);

    for (i = 0; i < 3; i++)
    {
        acolar(&lista, &i);
        ingresarCliente(&idx);
        insertar(&arbol, &idx, compararClientes);
    }

    eliminarDeCola(&arbol, &lista, "resultado.bin");
    mostrarArchivo("resultado.bin");

    printf("Cola vacia: %d", colaVacia(&lista));

    return 0;
}
