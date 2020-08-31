#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "funciones.h"

int main()
{
    t_arbol arbol;
    crearArbol(&arbol);

    generarLote("empleados.bin");
    guardarIndiceEnArbol(&arbol, "empleados.bin");
    generarArchivoIndice(&arbol, "indice.idx");
    ordenarArchivo("empleados.bin", "indice.idx", "resultado.bin");
    mostrarArchivo("resultado.bin");
    return 0;
}
