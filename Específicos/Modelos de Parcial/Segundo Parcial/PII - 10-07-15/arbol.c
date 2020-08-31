#include "arbol.h"

/** Borrar nodo, pasos:

	1. Buscar la clave devuelve la dir del padre
		Si existe, guardar la informacion de esa clave (en el t_dato, devolver)
		Si no existe, retornar nulo
	2. Eliminar_raiz
		Si es hoja, corta, pone nulo, y vuelve
		Si no es hoja, busco la altura por izq y por der. Si la altura de la izq es mayor busco el mayor de los menores. Si la altura
		de la derecha es mayor, busco el menor de los mayores.

		Piso el nodo.
		Y despues hago eliminar raiz de aquel que encontré.
*/


void crearArbol(t_arbol * pa)
{
    *pa = NULL;
}


int insertarOrdenado(t_arbol * pa, t_dato * d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato.dni, &d->dni);

        if (cmp < 0)
            return insertarOrdenado(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            return insertarOrdenado(&(*pa)->izq, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        *pa = (t_nodo *) malloc(sizeof(t_nodo));

        if (!(*pa))
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->izq = NULL;
        (*pa)->der = NULL;

        return SUCCESS;
    }

    return SUCCESS;
}

int buscarClave(t_arbol * pa, t_dato * d, t_cmp comparar, t_accion accion)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato.dni, &d->dni);

        if (cmp < 0)
            return buscarClave(&(*pa)->der, d, comparar, accion);
        else if (cmp > 0)
            buscarClave(&(*pa)->izq, d, comparar, accion);
        else
            *d = (*pa)->dato;
    }
    else //Si no existe la clave...
        return 0;

    return SUCCESS;
}

/** Recorridos */

void inOrden(t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        inOrden(&(*pa)->izq, accion);
        accion(&(*pa)->dato, NULL);
        inOrden(&(*pa)->der, accion);
    }
    return;
}

/** Utilidades */

int compararDNI(const void * arg1, const void * arg2)
{
    int * dni1 = (int *) arg1, * dni2 = (int *) arg2;

    return *dni1-*dni2;
}

/** Extrae los datos del nodo */

int extraerNodo(const void * arg1, const void * arg2)
{
    t_arbol * pa;
    t_indice * idx = (t_indice *) arg2;

    if (!arg1)
    {
        idx->dni = -1;
        idx->numReg = -1;
    }
    else
    {
        pa = (t_arbol *) arg1;
        *idx = (*pa)->dato;
    }

    return SUCCESS;
}

int eliminar_de_arbol(t_arbol *pa, t_dato *d, t_cmp comparar)
{
    int cmp;

    while((*pa) && (cmp=comparar(&(*pa)->dato.dni, &d->dni) != 0))
    {
        if(cmp > 0)
            pa = &(*pa)->der;
        else
            pa = &(*pa)->izq;
    }

    if(!*pa)
        return NOT_FOUND;

    eliminar_raiz(pa);

    return SUCCESS;
}

/** Eliminar_raiz*/
int eliminar_raiz(t_arbol *pa)
{
    int hi, hd; //Altura derecha, altura izquierda
    t_arbol * remp;

    //Si es una hoja, lo eliminamos directamente
    if(!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return SUCCESS;
    }

    //Calculamos la altura de los subarboles izquierdos y derechos
    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    //Si la altura izquierda es mayor, buscamos al mayor de los menores
    if(hi > hd)
        remp = buscarMayor(&(*pa)->izq);
    //Caso contrario, si la altura derecha es mayor, buscamos al menor de los mayores
    else
        remp = buscarMenor(&(*pa)->der);

    //Pisamos el dato del nodo que queremos borrar
    (*pa)->dato = (*remp)->dato;
    //Borramos al nodo que usamos como reemplazo, ejecutando el mismo código
    eliminar_raiz(remp);

    return SUCCESS;
}

int alturaArbol(const t_arbol * pa)
{
    int hi, hd;

    if(!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    return hi > hd ? hi+1 : hd+1;
}

t_arbol * buscarMenor (t_arbol * pa)
{
    while((*pa)->izq)
        pa = &(*pa)->izq;
    return pa;
}

t_arbol * buscarMayor(t_arbol * pa)
{
    while((*pa)->der)
        pa = &(*pa)->der;
    return pa;
}


/* Esta forma sirve, pero creo que no lo deja balanceado.
int borrarNodo(const void * arg, const void * arg2)
{
    t_arbol * pa = (t_arbol *) arg;
    t_nodo * aux;

    //Si es una hoja, borramos sin preocuparnos el nodo
    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return SUCCESS;
    }

    //Si no existe el hijo izquierdo, pero sí el derecho, borramos el nodo padre y le ponemos el derecho
    if (!(*pa)->izq && (*pa)->der)
    {
        aux = (*pa)->der;
        free(*pa);
        *pa = aux;
        return SUCCESS;
    }
    //Lo mismo pero con el nodo izquierdo
    else if (!(*pa)->der && (*pa)->izq)
    {
        aux = (*pa)->izq;
        free(*pa);
        *pa = aux;
        return SUCCESS;
    }

    //Si existen los dos hijos, buscamos en el arbol derecho el nodo que tenga la clave mas chica
    //Una vez que lo encontramos, asignamos el valor de ese nodo al padre, y borramos al mas chico de la misma forma que estamos borrando estos

    //Buscamos el minimo en el arbol derecho y lo asignamos
    (*pa)->dato = buscarMin(&(*pa)->der);
    //Ahora lo eliminamos del arbol derecho
    buscarClave(&(*pa)->der, &(*pa)->dato, compararDNI, borrarNodo);

    return SUCCESS;

}

t_dato buscarMin(t_arbol * pa)
{
    t_dato min;
    while (*pa)
    {
        min = (*pa)->dato;
        pa = &(*pa)->izq;
    }

    return min;
}*/
