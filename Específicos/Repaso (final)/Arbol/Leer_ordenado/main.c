#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "funciones.h"

/** Crea un arbol a partir de un archivo ordenado */

int main()
{
    t_arbol arbol;
    crearArbol(&arbol);
    generarLote("empleados.bin");
    generarArbol(&arbol, "empleados.bin");
    recorrerEnOrden(&arbol, mostrar);
    return 0;
}
