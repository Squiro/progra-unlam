#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    t_pila pila;

    crearPila(&pila, sizeof(t_empleado));
    generarLote();
    guardarEnPila(&pila);
    ordenarPila(&pila, compararEmpleados);
    generarArchivo(&pila);
    mostrarArchivo();
    return 0;
}
