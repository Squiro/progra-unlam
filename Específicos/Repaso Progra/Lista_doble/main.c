#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main()
{
    t_alumno alums[4] = { { 1, "Jose", 'M' }, { 1, "Jose", 'M' }, { 1, "Jose", 'M' }, { 1, "Jose", 'M' } };
    int i;
    t_lista lista;

    crearLista(&lista);

    for (i = 0; i < 4; i++)
        insertar(&lista, &alums[i], compararDNI);

    printf("Antes...\n\n");
    mostrarLista(&lista);
    eliminarDuplicados(&lista, compararDNI);
    printf("Despues...\n\n");
    mostrarLista(&lista);

    return 0;
}
