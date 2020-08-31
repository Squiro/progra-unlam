#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"
#include "arbol.h"

int main()
{
    t_lista lista;
    crearLista(&lista);
    t_alumno alum = { 1, "Alesio" }, search;

    search.dni = 1;

    insertar(&lista, &alum, compararDNI);
    buscarElemento(&lista, &search, compararDNI);

    printf("A ver: %s", search.nombre);
    return 0;
}
