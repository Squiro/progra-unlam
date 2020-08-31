#include "arbol.h"

void crearArbol(t_arbol * pa)
{
    *pa = NULL;
}

int arbolLleno(const t_arbol * pa)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));

    free(aux);

    return aux == NULL;
}

int arbolVacio(const t_arbol * pa)
{
    return *pa == NULL;
}

int alturaArbol(const t_arbol * pa)
{
    int altIzq, altDer;

    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    //Retornamos aquella altura que sea mayor, mas 1, por la raiz
    return  altIzq > altDer ? altIzq + 1 : altDer + 1;
}

/** Funciones que eliminan nodos */

void cortarHojas(t_arbol * pa)
{
    if (!(*pa))
        return;

    if (!(*pa)->izq && !(*pa)->der)
    {
        //Liberamos al nodo, le pasamos la direccion del nodo
        free(*pa);
        *pa = NULL;
    }
    else
    {
        cortarHojas(&(*pa)->izq);
        cortarHojas(&(*pa)->der);
    }
}

void podarHastaNivel(t_arbol * pa, int nivel)
{
    if (!(*pa))
        return;

    if (nivel >= 0 && !(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }
    else
    {
        podarHastaNivel(&(*pa)->izq, nivel-1);
        podarHastaNivel(&(*pa)->der, nivel-1);
    }
}

void podarHastaAltura(t_arbol * pa, int altura)
{
    if (!(*pa))
        return;

    if (altura >= 1 && !(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }
    else
    {
        podarHastaAltura(&(*pa)->izq, altura-1);
        podarHastaAltura(&(*pa)->der, altura-1);
    }
}

//Recorre en posorden y va elimiando los nodos de "abajo hacia arriba"
void eliminarArbol(t_arbol * pa)
{
    if (*pa)
    {
        eliminarArbol(&(*pa)->izq);
        eliminarArbol(&(*pa)->der);
        free(*pa);
        *pa = NULL;
    }
}

int eliminarDeArbol(t_arbol * pa, t_dato * d, t_cmp comparar)
{
    /* Esto huele apestoso. ¿Qué pasa si la raíz es, por ejemplo, el número 3, y yo estoy buscando el número 24?
    3 - 24 = -21
    cmp < 0, me muevo a la izquierda...

    Nunca voy a llegar al 24 así ni en pedo.

    int cmp;
    //Si la comparacion sigue siendo mayor que 0, quiere decir que el dato que buscamos es mas grande, por lo que tenemos
    //que movernos a la derecha
    while((*pa) && (cmp=comparar(&(*pa)->dato, d) != 0))
    {
        if(cmp > 0)
            pa = &(*pa)->der;
        else
            pa = &(*pa)->izq;
    }*/

    int cmp;

    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp > 0)
            pa = &(*pa)->izq;
        else
            eliminar_raiz(pa);
    }

    if(!*pa)
        return NOT_FOUND;

    return SUCCESS;
}

void eliminarRaiz(t_arbol * pa)
{
    int altIzq, altDer;
    t_arbol * remp;

    //Si es una hoja, lo borramos sin dudar
    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }

    //Si no es una hoja, debemos calcular las alturas de los subarboles izquierdos y derechos
    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    //Si la altura izquierda es mayor, busco al mayor de los menores
    if (altIzq > altDer)
        remp = buscarMayor(&(*pa)->izq);
    else //Si no, busco al menor de los mayores
        remp = buscarMenor(&(*pa)->der);

    //Pisamos el dato que queremos borrar
    (*pa)->dato = (*remp)->dato;
    //Eliminamos el reemplazo
    eliminarRaiz(remp);
}

/** Recorridos recursivos */

//R I D
void preOrden(t_arbol * pa, t_accion accion)
{
    //Siempre chequear si pa es nulo o no... tenemos que saber si existe el nodo
    if (*pa)
    {
        accion(&(*pa)->dato);
        preOrden(&(*pa)->izq, accion);
        preOrden(&(*pa)->der, accion);
    }
}

//I R D
void inOrden(t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        inOrden(&(*pa)->izq, accion);
        accion(&(*pa)->dato);
        inOrden(&(*pa)->der, accion);
    }
}

//I D R
void posOrden(t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        posOrden(&(*pa)->izq, accion);
        posOrden(&(*pa)->der, accion);
        accion(&(*pa)->dato);
    }
}

/** Insertar clave */

int insertar(t_arbol * pa, const t_dato * d, t_cmp comparar)
{
    //¿Hay  raíz?
    if (*pa)
    {
        int cmp = comparar(&(*pa)->dato, d);

        //Datos mayores que la raiz van a la derecha del arbol
        if (cmp < 0)
            insertar(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            insertar(&(*pa)->izq, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

        if (!nuevo)
            return SIN_MEM;

        //Asignamos el dato
        nuevo->dato = *d;
        //Seteamos los punteros izq y der en nulo
        nuevo->der = NULL;
        nuevo->izq = NULL;
        //Cambiamos el nulo de *pa por el la direccion que tenga el nuevo nodo
        *pa = nuevo;
    }

    return SUCCESS;
}

int insertarIterativo(t_arbol * pa, const t_dato * d, t_cmp comparar)
{
    int cmp;

    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp > 0)
            pa = &(*pa)->izq;
        else
            return DUPLICADO;
    }

    //Nos podemos ahorrar una variable de esta forma...
    *pa = (t_nodo *) malloc(sizeof(t_nodo));

    if (!(*pa))
        return SIN_MEM;

    (*pa)->dato = *d;
    (*pa)->izq = NULL;
    (*pa)->der = NULL;

    return SUCCESS;
}

/** Funciones de busqueda */

int hallarNodo(const t_arbol * pa, t_dato * d, t_cmp comparar)
{
    int cmp;
    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp < 0)
            pa = &(*pa)->izq;
        else
            *d = (*pa)->dato;
    }

    return -1;
}

int buscarClaveMayor(const t_arbol * pa)
{
    if (!(*pa))
        return -1;

    int res = (*pa)->dato.dni;
    int izqRes = buscarClaveMayor(&(*pa)->izq);
    int derRes = buscarClaveMayor(&(*pa)->der);

    if (izqRes > res)
        res = izqRes;
    if (derRes > izqRes)
        res = derRes;

    return res;
}

int buscarNodoClaveMayor(const t_arbol *pa, t_dato * d, t_cmp comparar)
{
    d->dni = buscarClaveMayor(pa);
    hallarNodo(pa, d, comparar);
    return SUCCESS;
}

int buscarClaveMenor(const t_arbol * pa)
{
    if (!(*pa))
        return -1;

    int res = (*pa)->dato.dni;
    int izqRes = buscarClaveMenor(&(*pa)->izq);
    int derRes = buscarClaveMenor(&(*pa)->der);

    if (izqRes < res)
        res = izqRes;
    if (derRes < izqRes)
        res = derRes;

    return res;
}

int buscarNodoClaveMenor(const t_arbol * pa, t_dato * d, t_cmp comparar)
{
    d->dni = buscarClaveMenor(pa);
    hallarNodo(pa, d, comparar);
    return SUCCESS;
}

t_arbol * buscarMenor(t_arbol * pa)
{
    while ((*pa)->izq)
        pa = &(*pa)->izq;

    return pa;
}

t_arbol * buscarMayor(t_arbol * pa)
{
    while ((*pa)->der)
        pa = &(*pa)->der;

    return pa;
}

/** Funciones con archivos */

void guardarPreOrdenBin(t_arbol * pa, FILE * arch)
{
    if (!(*pa))
        return;
    fwrite(&(*pa)->dato, sizeof(t_dato), 1, arch);
    guardarPreOrdenBin(&(*pa)->izq, arch);
    guardarPreOrdenBin(&(*pa)->der, arch);
}

void leerPreOrdenBin(t_arbol * pa, FILE * arch, t_cmp comparar)
{
    t_dato d;
    rewind(arch);
    fread(&d, sizeof(t_dato), 1, arch);

    while (!feof(arch))
    {
        insertarIterativo(pa, &d, comparar);
        fread(&d, sizeof(t_dato), 1, arch);
    }
}

int leerEnOrdenBin(t_arbol * pa, FILE * arch, int ini, int fin, t_cmp comparar)
{
    t_dato dato;
    int mid = (ini+fin)/2;

    if (ini > fin)
        return 0;
    //Buscamos
    fseek(arch, mid*sizeof(t_dato), SEEK_SET);
    fread(&dato, sizeof(t_dato), 1, arch);

    insertar(pa, &dato, comparar);
    leerEnOrdenBin(&(*pa)->izq, arch, ini, mid-1, comparar);
    leerEnOrdenBin(&(*pa)->der, arch, mid+1, fin, comparar);

    return SUCCESS;
}

