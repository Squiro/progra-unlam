#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "lista_simp.h"

int main()
{
    t_lista lista;
    crearLista(&lista);

    generarLote("pedidos.bin");
    guardarEnLista(&lista, "pedidos.bin");
    guardarListaEnArchivo(&lista, "resultado.bin");
    mostrarArchivo("resultado.bin");
    return 0;
}
