#include "lista_din.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int insertarPrincipio(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    //Asignamos el dato al nuevo nodo
    nuevo->dato = *d;
    //Al sig le asignamos el nodo al que apunta la lista actualmente (el anterior "primero")
    nuevo->sig = *pl;
    //Cambiamos el primer elemento de la lista por este nodo
    *pl = nuevo;

    return SUCCESS;
}

//Utilizamos el puntero a lista, haciendo que siempre apunte al "siguiente" del nodo
int insertarFinal(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    //Asigno el dato al nuevo nodo creado
    nuevo->dato = *d;
    //Asigno nulo al siguiente del nuevo nodo, porque es el ultimo
    nuevo->sig = NULL;

    //PL vale 1010, pero quiero ver el contenido de PL, que es 800 (por eso usamos el asterisco)
    //pero no quiero el 800, quiero ver el que le sigue a 800 (por eso usamos ->sig)
    //pero no quiero el siguiente nodo en su totalidad, quiero la direccion del siguiente, por eso uso el ampersand
    //PL siempre apunta a la parte de la estructura de nodo que tiene al siguiente
    //pl = %(*pl)->sig;

    //TL;DR lo que hacemos es almacenar la direccion del "sig", y despues chequeamos si el contenido
    //de esa direccion es nulo o no

    //Mientras que el contenido de PL no sea nulo, movemos la lista
    //acordarse acerca de que PL tiene un puntero a puntero de t_nodo
    while (*pl)
        pl = &(*pl)->sig;

    *pl = nuevo;

    /* Podemos ahorrarnos una variable

    *pl = (t_nodo *) malloc(sizeof(t_nodo));
    if (!*pl)
        return SIN_MEM;
    *pl->dato = *d;
    *pl->sig = NULL;

    */

    return SUCCESS;
}

int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));
    //Tengo que enviarle a comparar el actual dato, y el dato del que le sigue

    if (!nuevo)
        return SIN_MEM;

    //Antes de empezar a recorrer, necesito saber si es nulo el nodo
    //Debemos reccorer mientras que sea mayor igual a 0
    while (*pl && comparar(d, &(*pl)->dato) > 0)
        pl = &(*pl)->sig;

    //Asignamos el dato al nuevo nodo
    nuevo->dato = *d;
    //Como el contenido de pl es la parte "sig" de la estructura del nodo, el siguiente de nuevo
    //va a ser el contenido de pl
    nuevo->sig = *pl;
    //Al contenido de pl (que es la parte de la estructura "sig" del nodo actual), le asignamos el nuevo
    *pl = nuevo;

    return SUCCESS;
}

int quitarPrimero(t_lista *pl, t_dato *d)
{
    t_nodo * aux;

    //La lista apunta a un t_nodo, necesitamos el contenido
    aux = *pl;
    //Como vamos a sacar el primero, la lista tiene que apuntar al siguiente
    *pl = aux->sig;
    *d = aux->dato;
    //Liberamos el nodo que sacamos
    free(aux);

    return SUCCESS;
}

int quitarUltimo(t_lista *pl, t_dato *d)
{
    if (!*pl)
        return LISTA_VACIA;

    //Mientras que el siguiente no sea nulo
    //Acordarse de que estamos apuntando a la direccion dentro de la estructura que contiene a la direccion del siguiente
    while ((*pl)->sig)
        pl = &(*pl)->sig;

    *d = (*pl)->dato;
    //Liberamos el siguiente nodo
    free(*pl);
    *pl = NULL;

    return SUCCESS;
}

int quitarClave(t_lista *pl, t_dato *d, t_cmp comparar)
{
    t_nodo * aux;
    int cmp = 0;

    while (*pl && (cmp = comparar(d, &(*pl)->dato)) > 0)
        pl = &(*pl)->sig;

    //CMP tiene que ser distinto de 0
    if (!(*pl) || cmp)
        return NOT_FOUND;

    //printf("Debug");
    aux = *pl;
    *pl = aux->sig;
    strcpy(d->nombre, aux->dato.nombre);
    free(aux);

    return SUCCESS;
}

int quitarDuplicados(t_lista *pl, t_cmp comparar)
{
    t_lista * pLec = &(*pl)->sig;
    t_nodo * aux;

    if (!(*pl))
        return LISTA_VACIA;

    while (*pl)
    {
        while (*pLec)
        {
            if (comparar(&(*pLec)->dato, &(*pl)->dato) == 0)
            {
                aux = (*pLec)->sig;
                free(*pLec);
                *pLec = aux;

            }
            else
                pLec = &(*pLec)->sig;
        }

        pl = &(*pl)->sig;
        //Vamos al sig
        pLec = &(*pl)->sig;
    }

    return SUCCESS;

}

int quitarTodosDuplicados(t_lista *pl, t_cmp comparar)
{
    t_lista * pLec = &(*pl)->sig;
    t_nodo * aux;
    int duplicado = 0;

    if (!(*pl))
        return LISTA_VACIA;

    while (*pl)
    {
        while (*pLec)
        {
            if (comparar(&(*pLec)->dato, &(*pl)->dato) == 0)
            {
                duplicado = 1;
                aux = (*pLec)->sig;
                free(*pLec);
                *pLec = aux;

            }
            else
                pLec = &(*pLec)->sig;
        }

        //Como queremos eliminar todas las ocurrencias de los duplicados...
        //Al salir del while, *pl apunta al nodo fijo que utilizamos para ver si habia duplicados
        //Si encontramos algun duplicado, lo borramos

        //El problema es, que pasa si ese nodo es el primero de la lista? y que pasa si NO lo es?
        //Si ese nodo es el primero de la lista, necesitamos modificar el contenido de 2020, el puntero original
        //Si no es el primero de la lista, necesitamos modificar el "siguiente" del nodo
        //Lo bueno es que al movernos utilizando &aux->sig, esto se soluciona sin hacer nada mas.
        aux = *pl;
        if (duplicado)
        {
            //Reseteamos duplicado para evitar problemillas
            duplicado = 0;
            *pl = aux->sig;
            free(aux);
        }
        pl = &aux->sig;//&(*pl)->sig;
        //Vamos al sig
        pLec = &(*pl)->sig;
    }

    return SUCCESS;
}

//Necesitamos recorrer la lista desde el principio todo el tiempo, y si encontramos un duplicado
//dejamos de recorrer, avanzamos un elemento, y repetimos
//Si no encontramos duplicados, eliminamos el que no está duplicado, y nos vamos
int quitarNoDuplicados(t_lista *pl, t_cmp comparar)
{
    t_lista * pIni = pl;
    t_lista * pLec = pIni;
    t_nodo * aux;
    int duplicado = 0;

    if (!(*pl))
        return LISTA_VACIA;

    while (*pl)
    {
        //
        while (*pLec && !duplicado)
        {
            if (*pl != *pLec)
                duplicado = !comparar(&(*pLec)->dato, &(*pl)->dato);

            pLec = &(*pLec)->sig;
        }

        if (!duplicado)
        {
            aux = *pl;
            *pl = aux->sig;
            free(aux);
        }
        else
            pl = &(*pl)->sig;

        pLec = pIni;
        duplicado = 0;
    }
    return SUCCESS;
}

/** Federico Pezzola dijo:

(haciendo referencia a mover solamente los datos en vez de las direcciones de los nodos):
[...] si bien tu código es mas corto, en la mayoría de los casos no es el mas eficiente, el problema es que la info que guarda el nodo por lo general es mas grande que los punteros de los nodos.
Entonces si, por ejemplo, tenes una info de 20 bytes, para hacer el intercambio moves 60 bytes, cuando en el otro codigo, en el peor de los casos, se mueven 24 bytes (en una maquina de 32 bits).

Federico Pezzola dijo:

Algo que agregar al codigo (o sacar), es que, si bien el algoritmo de seleccion dice que hay que intercambiar los datos, cuando trabajamos con una lista simplemente enlazada,
es mas facil y no afecta al funcionamiento, sacar el menor de donde esta y ponerlo delante del nodo actual, es decir, reinsertarlo. Es mas facil, mas corto y mas eficiente...
*/

int ordernarLista(t_lista *pl, t_cmp comparar)
{
    t_lista * menor;
    t_nodo * aux, * menSig;

    while (*pl)
    {
        menor = hallarMenor(pl, comparar);

        if (menor != pl)
        {
            /*Hay un caso especial que hay que tener en consideración:
            Cuando el menor sea igual al siguiente del elemento actual.
            */
            aux = *pl;
            *pl = *menor;
            menSig = (*menor)->sig;
            (aux->sig == *menor) ? ((*pl)->sig = aux) : ((*pl)->sig = aux->sig);
            *menor = aux;
            (*menor)->sig = menSig;

            /* Se puede optimizar mas, ahorrandose un puntero:

            aux=(*menor)->sig;
            if((*pl)->sig==*menor)
            {
                (*menor)->sig=*pl;
                *pl=*menor;
                *menor=aux;
            }
            else
            {
                (*menor)->sig=(*pl)->sig;
                (*pl)->sig=aux;
                aux=(*menor);
                *menor=*pl;
                *pl=aux;
            }*/
        }
        pl = &(*pl)->sig;
    }

    return SUCCESS;

}

void * hallarMenor(t_lista *pl, t_cmp comparar)
{
    t_lista * menor = pl;

    while (*pl)
    {
        if (comparar(&(*pl)->dato, &(*menor)->dato) < 0)
            menor = pl;

        pl = &(*pl)->sig;
    }

    return menor;
}

int compararEnteros(const void * arg1, const void * arg2)
{
    int * dato1 = (int *) arg1, * dato2 = (int *)arg2;

    return *dato1-*dato2;
}

int compararEmp(const void * arg1, const void * arg2)
{
    t_dato * dato1 = (t_dato *) arg1, * dato2 = (t_dato *)arg2;

    return dato1->id-dato2->id;
}

void recorrerLista(t_lista *pl)
{
    while (*pl)
    {
        printf("%d\n", (*pl)->dato.id);
        printf("%s\n", (*pl)->dato.nombre);
        pl = &(*pl)->sig;
    }
}
