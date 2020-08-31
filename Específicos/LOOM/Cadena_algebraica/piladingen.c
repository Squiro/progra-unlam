#include "piladingen.h"

void crearPila(t_pila *p, int tamElem)
{
    //Al ultimo nodo que está guardado, le asignamos null
    p->pila = NULL;
    p->tamElem = tamElem;
}

//Asignamos memoria con el tamaño de un nodo y verificamos si se pudo o no lograr esa asignacion
int pilaLlena(const t_pila *p)
{
    void * nuevo = malloc(p->tamElem);

    free(nuevo);
    return !nuevo;
}

//Nos fijamos si el actual ultimo elemento de la pila es nulo
int pilaVacia(const t_pila *p)
{
    //Necesitamos ver si a lo que apunta la pila (que siempre va a ser el ultimo elemento) es a NULL o no
    return p->pila == NULL;
}

int apilar(t_pila *p, const void *d)
{
    //Asigno memoria para un nuevo elemento de la pila y casteandolo al tipo t_nodo
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));
    //Asigno memoria para el dato dentro del nodo, utilizando tamElem
    nuevo->dato = malloc(p->tamElem);

    if (!nuevo || !nuevo->dato)
    {
        //Si alguna de las dos falla, nos vamos, pero antes liberamos memoria
        free(nuevo);
        free(nuevo->dato);
        return SIN_MEM;
    }

    //Copio el dato que me llega dentro del nodo
    memmove(nuevo->dato, d, p->tamElem);
    //Indico que el elemento que le sigue a este es el anterior que se encontraba en el tope
    nuevo->sig = p->pila;
    //Le indico a la pila cual es el nuevo tope, que sera el mismo nuevo
    p->pila = nuevo;

    return SUCCESS;
}

int desapilar(t_pila *p, void *d)
{
    //Creo y asigno un puntero a t_nodo provisorio con los mismos contenidos que el actual tope de la pila
    t_nodo * elim = p->pila;

    if (!p->pila)
        return PILA_VACIA;

    //Copio el dato del elemento a eliminar... antes de eliminarlo
    memmove(d, elim->dato, p->tamElem);
    //Le indico a la pila que el nuevo tope va a ser el elemento que le sigue al que vamos a eliminar
    //p->pila es un puntero a t_nodo, y elim->sig también, por lo tanto la asignación es bastante simple
    p->pila = elim->sig;
    //Liberamos la memoria ocupada por el dato
    free(elim->dato);
    //Liberamos la memoria ocupada por el nodo en sí
    free(elim);

    return SUCCESS;
}

int verTope(const t_pila *p, void * d)
{
    if (p->pila == NULL)
        return PILA_VACIA;

    //Destination, source, size
    memmove(d, p->pila->dato, p->tamElem);
    return SUCCESS;
}

void vaciarPila(t_pila *p)
{
    t_nodo * elim = p->pila;

    while (!p->pila)
    {
        p->pila = elim->sig;
        free(elim->dato);
        free(elim);
        elim = p->pila;
    }
}
