#include "lista_circ.h"

void crear_lista(t_lista *pl)
{
    *pl = NULL;
}

int lista_vacia(t_lista *pl)
{
    return *pl == NULL;
}

int insertar_al_principio(t_lista *pl, t_dato *d)
{
    t_nodo * nue;
    nue = (t_nodo *) malloc(sizeof(t_nodo));

    if(!nue)
        return LISTA_LLENA;

    nue->dato = *d;

    if(*pl == NULL)     // si es el primer elemento de la lista, su insersion es diferente
    {
        *pl = nue;
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*pl)->sig;
        (*pl)->sig = nue;
    }

    return SUCCESS;
}

int insertar_al_final(t_lista *pl, t_dato *d)
{
    t_nodo *nue;
    nue = (t_nodo *) malloc(sizeof(t_nodo));

    if(nue==NULL)
        return LISTA_LLENA;

    nue->dato = *d;

    if(*pl == NULL)     // si es el primer elemento de la lista, su insersion es diferente
    {
        *pl = nue;
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*pl)->sig;
        (*pl)->sig = nue;
        *pl = nue;
    }

    return SUCCESS;
}

int insertar_ordenado(t_lista *pl, t_dato *d, t_cmp comparar) //de menor a mayor
{
    t_nodo *nue, **p_inicio;
    int bandera = 0;
    p_inicio = pl;
    nue = (t_nodo *) malloc(sizeof(t_nodo));

    if(!nue)
        return LISTA_LLENA;

    nue->dato = *d;     // asigno el dato desde el inicio

    if(*pl == NULL)     // si es el primer elemento de la lista, su insersion es diferente
    {
        *pl = nue;
        nue->sig = nue;
    }
    else
    {
        while(comparar(&(*pl)->sig->dato,d)<0 && (*p_inicio!=*pl || bandera==0))
/*
        recorre la lista mientras que el dato sea mayor al elemento de la lista o hasta que llegue al final de la misma
        la bandera es necesaria, pues el puntero a lista apunta al final
*/
        {
            pl = &(*pl)->sig;
            bandera = 1;
        }
        nue->sig = (*pl)->sig;
        (*pl)->sig = nue;
        if(*pl == *p_inicio && bandera == 1)    // si fue el ultimo elemento de la lista, hay que actualizar
            *p_inicio = nue;

    }

    return SUCCESS;
}

int comparacion(const void * dato1, const void * dato2)
{
    return *(int *)dato1 - *(int *)dato2;
}

int quitar_del_principio(t_lista *pl,t_dato *d)
{
    t_nodo *aux;

    if(!(*pl))
        return LISTA_VACIA;

    *d = (*pl)->sig->dato;  // doy el dato
    if(*pl != (*pl)->sig)   // pregunto si es el unico elemento
    {
        aux = (*pl)->sig;
        (*pl)->sig = aux->sig;
        free(aux);
    }
    else        // si es el unico elemento, libero el nodo y reinicio la lista circular
    {
        free(*pl);
        *pl = NULL;
    }
    return SUCCESS;
}







