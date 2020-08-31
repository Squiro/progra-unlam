#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "lista_simp.h"

int main()
{
    char * mat[20];
    t_lista lista;

    crearLista(&lista);
    almacenarCadenas(mat);
    mostrarCadenas(mat);
    guardarEnLista(&lista, mat);
    mostrarLista(&lista);

    return 0;
}
