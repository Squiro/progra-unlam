#include "lista_simp.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int listaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));
    int cmp;

    if (!nuevo)
        return SIN_MEM;

    while (*pl && (cmp = comparar(&(*pl)->dato, d)) < 0)
        pl = &(*pl)->sig;

    if (!cmp)
    {
        (*pl)->dato.cant += d->cant;
    }
    else
    {
        nuevo->dato = *d;
        nuevo->sig = *pl;
        *pl = nuevo;
    }

    return SUCCESS;
}

int quitarPrimero(t_lista *pl, t_dato *d)
{
    t_nodo * aux = *pl;

    if (!aux)
        return -1;

    *d = aux->dato;
    *pl = aux->sig;
    free(aux);

    return SUCCESS;
}

int actualizarInfo(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    while (*pl && comparar(&(*pl)->dato, d) != 0)
        pl = &(*pl)->sig;

    if (!(*pl))
        return 0;

    (*pl)->dato.cant += d->cant;

    return SUCCESS;
}

int compararPedidos(const void *arg1, const void *arg2)
{
    t_pedido * ped1 = (t_pedido *) arg1, *ped2 = (t_pedido *) arg2;

    return ped1->nroPedido - ped2->nroPedido;
}

int compararArticulos(const void *arg1, const void *arg2)
{
    t_pedido * ped1 = (t_pedido *) arg1, * ped2 = (t_pedido *) arg2;

    return mi_atoi(ped1->nroArticulo) - mi_atoi(ped2->nroArticulo);
}

int mi_atoi(char *str)
{
    int sgn = 1, num = 0;

    if (*str == '-')
    {
        sgn = -1;
        str++;
    }

    while (*str)
    {
        num += num * 10 + (*str - '0');
        str++;
    }

    return num*sgn;
}
