#include "lista_simp.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int listaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

int insertar(t_lista *pl, const t_dato *d, t_cmp comparar)
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

int sacarPrimero(t_lista *pl, t_dato *d)
{
    t_nodo * aux = *pl;
    if (!*pl)
        return LISTA_VACIA;

    *d = aux->dato;
    *pl = aux->sig;
    free(aux);

    return SUCCESS;
}

void vaciarLista(t_lista *pl)
{
    t_nodo * aux = *pl;

    while (aux)
    {
        *pl = aux->sig;
        free(aux);
        aux = *pl;
    }
}
