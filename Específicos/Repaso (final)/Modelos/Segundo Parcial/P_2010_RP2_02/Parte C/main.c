#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "arbol.h"

int main()
{
    t_arbol arbol;
    crearArbol(&arbol);
    generarLote("cuentas.bin");
    darBajaInactivas(&arbol, "cuentas.bin");
    generarArchivo(&arbol, "resultado.bin");
    mostrarArchivo("resultado.bin");
    return 0;
}
