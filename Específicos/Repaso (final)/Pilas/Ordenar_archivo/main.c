#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "pila.h"

int main()
{
    char ruta[] = "empleados.bin";
    t_pila pila1;

    crearPila(&pila1);

    generarLote(ruta);
    guardarEnPila(&pila1, ruta);
    ordenarPila(&pila1, compararDNI);
    generarResultado(&pila1, "resultado.bin");
    mostrarArchivo("resultado.bin");

    return 0;
}
