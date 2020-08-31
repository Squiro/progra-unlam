#include "lista_circ.h"

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

void listaVacia(t_lista * pl)
{
    return *pl == NULL;
}

int insertarPrincipio(t_lista * pl, t_dato * d)
{

}


/* Cola circ */

/** El puntero apunta al ultimo elemento de la cola. */

void crearCola(t_lista * pl)
{
    *pl = NULL;
}

int verTopeCola(t_lista * pl, t_dato * d)
{
    if (!(*pl))
        return COLA_VACIA;

    *d = (*pl)->dato;
}

int acolar(t_lista * pl, const t_dato * d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;

    if (!(*pl))
    {
        //Lo hacemos apuntar a sí mismo
        nuevo->sig = nuevo;
        *pl = nuevo;
    }
    else
    {
        //Hacemos que el sig del nuevo apunte al "ultimo" de la cola
        nuevo->sig = (*pl)->sig;
        //Y ahora hacemos que el primero apunte al nuevo
        (*pl)->sig = nuevo;
    }

    return SUCCESS;
}

int desacolar(t_lista * pl, const t_dato * d)
{
    t_nodo * aux;
    t_lista * pIni = pl;

    if (!(*pl))
        return COLA_VACIA;

    aux = *pl;
    *d = aux->dato;

    //Vamos al segundo elemento de la cola (el que esta antes del primero en salir)
    while ((*pl)->sig != *pIni)
        pl = &(*pl)->sig;

    //Si el elemento que queremos desacolar es el unico de la lista... (porque los siguientes apuntan al mismo)
    if ((*pl)->sig == aux->sig)
        *pl = NULL;
    else
        (*pl)->sig = aux->sig; //Hacemos que el primero apunte al ultimo

    //Indicamos que se cambio el primer elemento
    *pIni = *pl;
    free(aux);

    return SUCCESS;
}

void vaciarCola(t_lista * pl)
{
    t_nodo * aux;

    //Mientras que pl no sea el unico nodo que quede (o sea, mientras que se apunte a sí mismo)
    while (*pl != (*pl)->sig)
    {
        aux = (*pl)->sig;
        (*pl)->sig = aux->sig;
        free(aux);
    }

    free(*pl);
    *pl = NULL;
}
