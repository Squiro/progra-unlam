#include "lista_simp.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int listaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

int insertarEnOrden(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    while (*pl && comparar(&(*pl)->dato, d) < 0)
        pl = &(*pl)->sig;

    nuevo->dato = *d;
    nuevo->sig = *pl;
    *pl = nuevo;

    return SUCCESS;
}

int obtenerInfo(const t_lista *pl, t_dato *d, t_cmp comparar)
{
    while (*pl && comparar(&(*pl)->dato, d) != 0)
        pl = &(*pl)->sig;

    if (!(*pl))
        return 0;

    *d = (*pl)->dato;

    return 1;
}

int actualizarInfo(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    while (*pl && comparar(&(*pl)->dato, d) != 0)
        pl = &(*pl)->sig;

    if (!(*pl))
        return 0;

    (*pl)->dato = *d;

    return 1;
}

int compararPedidos(const void *arg1, const void *arg2)
{
    t_pedido * ped1 = (t_pedido *) arg1, * ped2 = (t_pedido *) arg2;

    return ped1->numPedido - ped2->numPedido;
}
