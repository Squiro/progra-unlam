#include "colagen.h"

void crearCola(t_cola *c, int tamElem)
{
    c->tamElem = tamElem;
    c->primero = NULL;
    c->ultimo = NULL;
}

int colaLlena(const t_cola *c)
{
    //Es indistinto que usemos el casteo acá, porque lo que nos interesa es si pudimos o no asignar memoria
    void * nuevo = malloc(sizeof(t_nodo));

    free(nuevo);
    return !nuevo;
}

int colaVacia(const t_cola *c)
{
    return c->primero == NULL;
}

int acolar(t_cola *c, const void *d)
{
    //Reservo memoria para un nuevo nodo
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));
    //Reservo memoria para el dato que voy a encolar, usando tamElem
    nuevo->dato = malloc(c->tamElem);

    //Si no puedo reservar alguno de los dos, me voy
    if (!nuevo || !nuevo->dato)
        return SIN_MEM;

    //Copiamos el dato que nos llega al bloque de memoria que reservamos
    memmove(nuevo->dato, d, c->tamElem);
    //Como es el ultimo que agregamos, el siguiente va a ser nulo. Lamentablmente no somos videntes y no podemos saber la direccion del dato que va a venir despues.
    nuevo->sig = NULL;

    //Tenemos que chequear si este "ultimo en ser agregado" es tambien el primer elemento de la cola
    //Esto va a pasar cuando la cola este vacia y apilemos un elemento
    if (!c->ultimo)
        c->primero = nuevo;
    //Pero si no resulta ser el primero, al anterior "ultimo" (que ahora va a ser anteultimo) le tenemos que indicar quien le sigue (el nuevo ultimo)
    else
        c->ultimo->sig = nuevo;

    //Como es el ultimo en ser agregado, obviamente va a ser el ultimo elemento de la cola
    c->ultimo = nuevo;

    return SUCCESS;
}

int desacolar(t_cola *c, void *d)
{
    //Creamos un auxiliar y le asignamos el elemento a desapilar
    t_nodo * elim = c->primero;

    //Si no hay primero, no hay ningun elemento en la cola
    if (!c->primero)
        return COLA_VACIA;

    //Copio el dato a d antes de liberar memoria
    memmove(d, elim->dato, c->tamElem);
    //Tenemos un nuevo primero, lo asignamos
    c->primero = c->primero->sig;

    //¿Que pasa si el elemento que desapilamos era el ultimo de la cola?
    //Tenemos que reflejar ese cambio en c->ultimo, porque ya no va a haber más ningun ultimo
    if (!c->primero)
        c->ultimo = NULL;

    //Libero memoria del dato
    free(elim->dato);
    //Libero memoria del nodo
    free(elim);

    return SUCCESS;
}

int verTope(const t_cola *c, void *d)
{
    if (!c->primero)
        return COLA_VACIA;

    memmove(d, c->primero->dato, c->tamElem);
    return SUCCESS;
}

void vaciarCola(t_cola *c)
{
    //Asignamos un puntero a nodo provisorio que contenga a primero
    t_nodo * elim = c->primero;

    //Mientras que no sea nulo...
    while (c->primero)
    {
        //Indicamos cual es el siguiente nodo
        c->primero = c->primero->sig;
        //Liberamos memoria
        free(elim->dato);
        free(elim);
        //Guardamos provisoriamente el nodo
        elim = c->primero;
    }
    //Asignamos nulo al ultimo
    c->ultimo = NULL;
}
