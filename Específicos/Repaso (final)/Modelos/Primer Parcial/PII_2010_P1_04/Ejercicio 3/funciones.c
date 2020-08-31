#include "funciones.h"

int generarLote(char * ruta)
{
    int i;
    FILE * arch;
    t_pedido peds[3] = { { 1, "0111", 5, 20 }, { 2, "0111", 5, 20 }, { 3, "0110", 3, 22 } };

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    for (i = 0; i < 3; i++)
        fwrite(&peds[i], sizeof(t_pedido), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int guardarEnLista(t_lista * pl, char * ruta)
{
    FILE * arch;
    t_pedido ped;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

    fread(&ped, sizeof(t_pedido), 1, arch);

    while (!feof(arch))
    {
        /*if (!actualizarInfo(pl, &ped, compararArticulos))*/
            insertarOrdenado(pl, &ped, compararPedidos);
        fread(&ped, sizeof(t_pedido), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int guardarListaEnArchivo(t_lista * pl, char * ruta)
{
    FILE * arch;
    t_pedido ped;
    arch = fopen(ruta, "wb");

    while (!listaVacia(pl))
    {
        quitarPrimero(pl, &ped);
        fwrite(&ped, sizeof(t_pedido), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int mostrarArchivo(char * ruta)
{
    FILE * arch;
    t_pedido ped;

    arch = fopen(ruta, "rb");

    if (!arch)
        return SIN_MEM;

    fread(&ped, sizeof(t_pedido), 1, arch);

    while (!feof(arch))
    {
        printf("numPed: %d", ped.nroPedido);
        printf("\nnumArt: %s", ped.nroArticulo);
        printf("\ncant: %d", ped.cant);
        printf("\ntotal: %f", ped.precioUnit * ped.cant);
        printf("\n\n");
        fread(&ped, sizeof(t_pedido), 1, arch);
    }

    return SUCCESS;
}

