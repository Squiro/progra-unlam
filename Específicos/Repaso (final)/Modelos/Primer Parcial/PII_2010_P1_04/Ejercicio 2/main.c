#include <stdio.h>
#include <stdlib.h>
#include "lista_simp.h"

int main()
{
    t_pedido pedido = { 1, 22.23 };
    t_lista lista;

    crearLista(&lista);
    insertarEnOrden(&lista, &pedido, compararPedidos);
    printf("TRUE: %d\n", obtenerInfo(&lista, &pedido, compararPedidos));
    pedido.importeTotal = 222;
    printf("ACT: %d\n", actualizarInfo(&lista, &pedido, compararPedidos));
    return 0;
}
