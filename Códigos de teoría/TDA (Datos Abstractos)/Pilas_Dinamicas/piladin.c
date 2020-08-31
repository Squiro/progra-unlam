#include "piladin.h"

void crearPila(t_pila *p)
{
    *p = NULL;
}

/*  Pasos para guardar un dato:

    1.- Reservo memoria para un nodo.
    2.- Si no se pudo, salgo. if(!mem)
    3.- Asignamos el dato.
    4.- En el siguiente nodo, asignamos lo que dice pila (la dir. del siguiente nodo).
    5.- En pila pongo la direccion del nuevo dato.

    ¿Pero si queremos ingresar el PRIMER dato? No pasa nada, porque el primer dato apunta a nulo, y la pila apunta a nulo también.

*/
int apilar(t_pila *p, const t_dato *d)
{
    //Creamos un PUNTERO a nodo, y le asignamos un espacio de memoria que contiene el tamaño de un nodo
    t_nodo * nodo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nodo)
        return SIN_MEM;

    //Al contenido de dato de la direccion, le asignamos el dato, o sea: asignamos el dato
    nodo->dato = *d;
    //Tenemos que asignar la direccion del sig. dato. Esta direccion siempre va a ser el contenido de pila.
    //NUNCA se pone p sin asterisco. p es la direccion de la variable de la pila.
    nodo->sig = *p;
    *p = nodo;

    return SUCCESS;
}

/* Pasos para desapilar un dato:

    0.- Defino un puntero auxiliar
    1.- ¿Hay pila? ¿De que marca es? ¿Es la del conejito rosa gay? Si no hay, me voy.
    2.- Asigno a aux al contenido de la pila
    3.- Guardo el dato (del auxiliar) en d
    4.- Asigno al contenido de la pila el siguiente nodo a eliminar (lo sabemos por el aux)
    5.- Libero aux
*/

int desapilar(t_pila *p, t_dato *d)
{
    t_nodo * aux = *p;

    if (!*p)
      return SIN_PILA;

    //aux = *p;
    *d = aux->dato; //(*p)->dato;
    *p = aux->sig; //(*p)-> sig;
    free(aux);

    return SUCCESS;
}

/*
  El procedimiento es similar al de desapilar, solo que iteramos con un while,
  mientras que haya contenido en la pila (o sea, que la dirección contenida dentro de pila sea distintaa null).
*/

void vaciarPila(t_pila *p)
{
  t_nodo * aux = *p;

  while (*p)
  {
    //aux = *p;
    *p = aux->sig;
    free(aux);
  }
}

int pilaVacia(const t_pila *p)
{
    return *p == NULL;
}

int pilaLlena(const t_pila *p)
{
    t_nodo * nuevo;

    nuevo = (t_nodo *) malloc(sizeof(t_nodo));
    free(nuevo);
    return !nuevo; //o nuevo == null
}

int verTope(const t_pila *p, t_dato *d)
{
    if (*p == NULL)
        return PILA_VACIA;

    *d = (*p)->dato;

    return SUCCESS;
}
