#include "arbol.h"
#include "piladin.h"

/** TO DO:

Recuperar arbol desde el archivo. (kinda done?)

/!\ IMPORTANTE: Ordenar con inorden desde archivo /!\

1. Contar todos los nodos de un arbol. (retorna cant)

2. Contar todas las hojas del arbol.

3. Contar todos los nodos no hojas.

4. Contar (mostrar) todos los nodos que cumplen una condicion (la clave es par, es mayor que letra, etc)

4.1 Contar todos los nodos que cumplen con una condicion del subarbol derecho

5. Contar todos los nodos que cumplen una condicion del subarbol derecho

5.1. Mostrar y contar los nodos con hijos por izquierda (o por derecha)

5.2. Mostrar y contar los nodos con hijos solo por izquierda (o solo por derecha)

6. Cortar las hojas

7. Vaciar el arbol

8. Mostrar todos los nodos de un nivel (o altura) dado

9. Mostrar todos los nodos hasta un nivel dado (inclusive o no inclusive)

10. Mostrar todos los nodos desde un nivel dado (inclusive o no inclusive)

11. Altura o nivel del arbol

12. Buscar el nodo con mayor clave (o con menor clave)

13. Buscar el nodo con mayor o menor dato (que no pertenece a la clave)

14. Podar el arbol a un nivel dado (o altura)

*/

/** Primitivas */

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int arbolVacio(t_arbol *pa)
{
    return *pa == NULL;
}

int arbolLLeno(t_arbol *pa)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));
    free(aux);

    return aux == NULL;
}

/** Cortar las hojas */

int cortarHojas(t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }
    else
    {
        cortarHojas(&(*pa)->izq);
        cortarHojas(&(*pa)->der);
    }

    return SUCCESS;
}


/** Elimina hojas hasta X nivel */

int podarHastaNivel(t_arbol * pa, int nivel)
{
    if (!(*pa))
        return 0;

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

    return SUCCESS;
}

int podarHastaAltura(t_arbol * pa, int altura)
{
    if (!(*pa))
        return 0;

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

    return SUCCESS;
}

void eliminarArbol(t_arbol *pa)
{
    if (*pa)
    {
        eliminarArbol(&(*pa)->izq);
        eliminarArbol(&(*pa)->der);
        free(*pa);
        *pa = NULL;
    }
}

/**
    nivel() = return alturaArbol-1;
*/

int alturaArbol(const t_arbol * pa)
{
    int altIzq, altDer;

    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    return  altIzq > altDer  ? altIzq + 1 : altDer + 1;
}

/** Elimina un nodo de un arbol dejandolo balanceado */
int eliminar_de_arbol(t_arbol *pa, t_dato *d, t_cmp comparar)
{
    /* Esto huele apestoso. �Qu� pasa si la ra�z es, por ejemplo, el n�mero 3, y yo estoy buscando el n�mero 24?
    3 - 24 = -21
    cmp < 0, me muevo a la izquierda...

    Nunca voy a llegar al 24 as� ni en pedo.

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
    //Borramos al nodo que usamos como reemplazo, ejecutando el mismo c�digo
    eliminar_raiz(remp);

    return SUCCESS;
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

/** Funciones recursivas */

/*

PRE: +*-832/4+53 R I D

IN: 8-3*2+4/5+3 I R D

POS: 83-2*453+/+ I D R

*/

//R I D
void preOrden(const t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        accion(&(*pa)->dato);
        preOrden(&(*pa)->izq, accion);
        preOrden(&(*pa)->der, accion);
    }
    return;
}

//I R D
void inOrden(const t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        inOrden(&(*pa)->izq, accion);
        accion(&(*pa)->dato);
        inOrden(&(*pa)->der, accion);
    }
    return;
}

//I D R
void posOrden(const t_arbol * pa, t_accion accion)
{
    if (*pa)
    {
        posOrden(&(*pa)->izq, accion);
        posOrden(&(*pa)->der, accion);
        accion(&(*pa)->dato);
    }
    return;
}

int insertarClaveRecursivo(t_arbol * pa, const t_dato * d, t_cmp comparar)
{
    if (*pa)
    {
        int cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            return insertarClaveRecursivo(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            return insertarClaveRecursivo(&(*pa)->izq, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

        if (!nuevo)
            return SIN_MEM;

        nuevo->dato = *d;
        nuevo->der = NULL;
        nuevo->izq = NULL;
        *pa = nuevo;

        return SUCCESS;
        //Alternativamente:
        /**pa = (t_nodo *) malloc(sizeof(t_nodo));

        if (!(*pa))
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->der = NULL;
        (*pa)->izq = NULL;
        return SUCCESS;
        */
    }

    return SUCCESS;
}

int insertarBalanceado(t_arbol * pa, FILE * arch, int ini, int fin, t_cmp comparar)
{
    t_dato dato;
    int mid = (ini+fin)/2;

    if (ini > fin)
    {
        //*pa = NULL;
        return 0;
    }

    /**pa = (t_nodo *) malloc(sizeof(t_nodo));

    if (!(*pa))
        return SIN_MEM;*/

    fseek(arch, mid*sizeof(t_dato), SEEK_SET);
    fread(&dato, sizeof(t_dato), 1, arch);

    //(*pa)->dato = idx;
    insertarClaveRecursivo(pa, &dato, comparar);

    insertarBalanceado(&(*pa)->izq, arch, ini, mid-1, comparar);
    insertarBalanceado(&(*pa)->der, arch, mid+1, fin, comparar);

    return SUCCESS;
}

/** Funciones iterativas */

//R I D
int preOrdenIterativo(t_arbol * pa, t_accion accion)
{
    t_pila pila;
    t_nodo * aux;

    crearPila(&pila);

    if (!(*pa))
        return ARBOL_VACIO;

    apilar(&pila, pa);

    while (!pilaVacia(&pila))
    {
        desapilar(&pila, &aux);
        accion(&aux->dato);

        if (aux->der)
            apilar(&pila, &aux->der);

        if (aux->izq)
            apilar(&pila, &aux->izq);
    }

    return SUCCESS;
}

//I R D
int inOrdenIterativo(t_arbol * pa, t_accion accion)
{
    t_pila pila;
    t_nodo * aux = *pa;

    crearPila(&pila);

    while (aux || !pilaVacia(&pila))
    {
        //Recorremos hasta el nodo que est� m�s a la izquierda, mientras que no sea nulo
        while (aux)
        {
            apilar(&pila, &aux);
            aux = aux->izq;
        }

        //Desapilamos y mostramos
        desapilar(&pila, &aux);
        accion(&aux->dato);
        aux = aux->der;
    }

    return SUCCESS;
}

//I R D
int posOrdenIterativo(t_arbol * pa, t_accion accion)
{
    if (!(*pa))
        return ARBOL_VACIO;

    t_pila pila;
    crearPila(&pila);
    //Apilamos la ra�z
    apilar(&pila, pa);

    t_nodo *prev = NULL;

    while (!pilaVacia(&pila))
    {
        t_nodo *curr;
        verTope(&pila, &curr);

        if (!prev || prev->izq == curr || prev->der == curr)
        {
            if (curr->izq)
                apilar(&pila, &curr->izq);
            else if (curr->der)
                apilar(&pila, &curr->der);
        }
        else if (curr->izq == prev)
        {
            if (curr->der)
                apilar(&pila, &curr->der);
        }
        else
        {
            accion(&curr->dato);
            desapilar(&pila, &curr);
        }
        prev = curr;
    }

    return SUCCESS;
}

int insertarClaveIterativo(t_arbol * pa, const t_dato * d, t_cmp comparar)
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

    *pa = (t_nodo *) malloc(sizeof(t_nodo));

    if (!(*pa))
        return SIN_MEM;

    (*pa)->dato = *d;
    (*pa)->izq = NULL;
    (*pa)->der = NULL;

    return SUCCESS;
}

/** Busqueda de claves (iterativas) */

//Verifica si el nodo se encuentra en el arbol
int existeClave(t_arbol *pa, const t_dato *d, t_cmp comparar)
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
            return FOUND;
    }

    return NOT_FOUND;
}

//Busca la clave y devuelve el contenido

int hallarNodo(const t_arbol * pa, t_dato * d, t_cmp comparar)
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
            *d = (*pa)->dato;
    }

    return -1;
}

/*t_dato hallarClave(t_arbol *pa, t_dato *d, t_cmp comparar)
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
            return (*pa)->dato;
    }

    return -1;
}*/

t_nodo * hallarDirClave(t_arbol *pa, t_dato *d, t_cmp comparar)
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
            return *pa;
    }

    return NULL;
}

//Halla la direccion del nodo padre que tiene como hijo a una de las claves
t_nodo * hallarDirPadreClave(t_arbol *pa, t_dato *d, t_cmp comparar)
{
    t_nodo * padre;
    int cmp;
    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
        {
            padre = *pa;
            pa = &(*pa)->der;
        }
        else if (cmp > 0)
        {
            padre = *pa;
            pa = &(*pa)->izq;
        }
        else
            return padre;

    }

    return NULL;
}

/** Puede recibir un dato que tenga una clave vac�a, o puede el dato ra�z del arbol y continuar desde ah� */
void buscarClaveMayor(const t_arbol * pa, t_dato * dato)
{
    if (!(*pa))
        return;

    if ((*pa)->dato.dni > dato->dni)
        *dato = (*pa)->dato;

    buscarClaveMayor(&(*pa)->izq, dato);
    buscarClaveMayor(&(*pa)->der, dato);
}

void buscarClaveMenor(const t_arbol * pa, t_dato * dato)
{
    if (!(*pa))
        return;

    if ((*pa)->dato.dni < dato->dni)
        *dato = (*pa)->dato;

    buscarClaveMayor(&(*pa)->izq, dato);
    buscarClaveMayor(&(*pa)->der, dato);
}

/* /!\ Esta funcion habr�a que adaptarla para que funcione con una estructura que tenga una clave

t_dato buscarNodoClaveMayor(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    int res = (*pa)->dato;
    int izqRes = buscarNodoClaveMayor(&(*pa)->izq);
    int derRes = buscarNodoClaveMayor(&(*pa)->der);

    if (izqRes > res)
      res = izqRes;
    if (derRes > res)
      res = derRes;

    return res;
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
}*/


/* /!\ Esta funcion habr�a que adaptarla para que funcione con una estructura que tenga una clave

t_dato buscarNodoClaveMenor(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    int res = (*pa)->dato;
    int izqRes = buscarNodoClaveMenor(&(*pa)->izq);
    int derRes = buscarNodoClaveMenor(&(*pa)->der);

    if (izqRes < res)
      res = izqRes;
    if (derRes < res)
      res = derRes;

    return res;
}*/

t_dato buscarNodoMayorDato(const t_arbol *pa)
{
    if (!(*pa))
        return 0;

    if (!(*pa)->der)
        return (*pa)->dato;

    return buscarNodoMayorDato(&(*pa)->der);
}

t_dato buscarNodoMenorDato(const t_arbol *pa)
{
    if (!(*pa))
        return 0;

    if (!(*pa)->izq)
        return (*pa)->dato;

    return buscarNodoMenorDato(&(*pa)->izq);
}

/** Guardar arbol en archivo en preorden */

void guardar_arbol_bin(const t_arbol* pa, FILE* arch)
{
    if(!(*pa))
        return;
    fwrite(&(*pa)->dato, sizeof(t_dato), 1, arch);
    guardar_arbol_bin(&(*pa)->izq, arch);
    guardar_arbol_bin(&(*pa)->der, arch);
}

void guardar_arbol_txt(const t_arbol* pa, FILE* arch)
{
    if(!(*pa))
        return;
    fprintf(arch, "%d|",(*pa)->dato);
    guardar_arbol_txt(&(*pa)->izq, arch);
    guardar_arbol_txt(&(*pa)->der, arch);
}

/** Recuperar desde archivo en preorden */

void leer_bin_preorden(t_arbol * pa, FILE * arch, t_cmp comparar)
{
    t_dato d;
    rewind(arch);
    fread(&d, sizeof(t_dato), 1 ,arch);

    while(!feof(arch))
    {
        insertarClaveIterativo(pa, &d, comparar);
        fread(&d, sizeof(t_dato), 1, arch);
    }
}

/** Contar nodos */

int contarNodos(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    return contarNodos(&(*pa)->der) + contarNodos(&(*pa)->izq) + 1;
}

int contarHojas(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->der == NULL && (*pa)->izq == NULL)
        return 1;
    else
        return contarHojas(&(*pa)->der) + contarHojas(&(*pa)->izq);
}

int contarNoHojas(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->der || (*pa)->izq)
        return contarNoHojas(&(*pa)->der) + contarNoHojas(&(*pa)->izq) + 1;
    else
        return 0;
}

/** Mostrar con una condicion */

int es_par(const void * num)
{
    int * arg = (int *) num;

    if (*arg % 2 == 0)
        return 1;
    else
        return 0;
}

int contarCondicion(const t_arbol * pa, t_cond condicion)
{
    if (!(*pa))
        return 0;

    if (condicion(&(*pa)->dato))
        return contarCondicion(&(*pa)->der, condicion) + contarCondicion(&(*pa)->izq, condicion) + 1;
    else
        return contarCondicion(&(*pa)->der, condicion) + contarCondicion(&(*pa)->izq, condicion);
}

/** 5. Contar nodos del subarbol derecho */

int contarNodosSubarbolDerecho(const t_arbol * pa)
{
    return contarNodos(&(*pa)->der);
}

/** 5.1. Mostrar y contar los nodos con hijos por izquierda (o por derecha) */

int contarHijosIzq(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->izq)
    {
        mostrar(&(*pa)->dato);
        return contarHijosIzq(&(*pa)->izq) + contarHijosIzq(&(*pa)->der) + 1;
    }

    return contarHijosIzq(&(*pa)->izq) + contarHijosIzq(&(*pa)->der);
}

int contarHijosDer(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->der)
    {
        mostrar(&(*pa)->dato);
        return contarHijosDer(&(*pa)->izq) + contarHijosDer(&(*pa)->der) + 1;
    }

    return contarHijosDer(&(*pa)->izq) + contarHijosDer(&(*pa)->der);
}

/** 5.2. Mostrar y contar los nodos con hijos solo por izquierda (o solo por derecha) */

int contarHijosSoloIzq(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->izq && !(*pa)->der)
    {
        mostrar(&(*pa)->dato);
        return contarHijosSoloIzq(&(*pa)->izq) + 1;
    }

    return contarHijosSoloIzq(&(*pa)->izq) + contarHijosSoloIzq(&(*pa)->der);
}

int contarHijosSoloDer(const t_arbol * pa)
{
    if (!(*pa))
        return 0;

    if ((*pa)->der && !(*pa)->izq)
    {
        mostrar(&(*pa)->dato);
        return contarHijosSoloDer(&(*pa)->der) + 1;
    }

    return contarHijosSoloDer(&(*pa)->izq) + contarHijosSoloDer(&(*pa)->der);
}

/** 8. Mostrar todos los nodos de un nivel (o altura) dado */

void mostrarNodosEnNivel(const t_arbol * pa, int nivel)
{
    if (!(*pa))
        return;

    if (nivel == 0)
        mostrar(&(*pa)->dato);
    else if (nivel > 0)
    {
        mostrarNodosEnNivel(&(*pa)->izq, nivel-1);
        mostrarNodosEnNivel(&(*pa)->der, nivel-1);
    }

    return;
}

void mostrarNodosEnAltura(const t_arbol * pa, int altura)
{
    if (!(*pa))
        return;

    if (altura == 1)
        mostrar(&(*pa)->dato);

    else if (altura > 1)
    {
        mostrarNodosEnAltura(&(*pa)->izq, altura-1);
        mostrarNodosEnAltura(&(*pa)->der, altura-1);
    }

    return;
}

/** 9. Mostrar todos los nodos hasta un nivel dado (inclusive o no inclusive)

0 incluye, 1 no incluye */

void mostrarNodosHastaNivel(const t_arbol *pa, int nivel, int inclusive)
{
    if (!(*pa))
        return;

    if (nivel - inclusive < 0)
        return;
    else
    {
        mostrar(&(*pa)->dato);
        mostrarNodosHastaNivel(&(*pa)->izq, nivel-1, inclusive);
        mostrarNodosHastaNivel(&(*pa)->der, nivel-1, inclusive);
    }
}

/** 10. Mostrar todos los nodos desde un nivel dado (inclusive o no inclusive) */

void mostrarNodosDesdeNivel(const t_arbol *pa, int nivel, int inclusive)
{
    if (!(*pa))
        return;

    if (nivel - !inclusive < 0)
        mostrar(&(*pa)->dato);

    mostrarNodosDesdeNivel(&(*pa)->izq, nivel-1, inclusive);
    mostrarNodosDesdeNivel(&(*pa)->der, nivel-1, inclusive);
}

int mostrarNodosDesdeNivelContar(const t_arbol *pa, int nivel, int inclusive)
{
    //int altIzq, altDer;

    if (!(*pa))
        return 0;

    if (nivel - !inclusive < 0)
    {
        mostrar(&(*pa)->dato);
        return mostrarNodosDesdeNivelContar(&(*pa)->izq, nivel-1, inclusive) +
         mostrarNodosDesdeNivelContar(&(*pa)->der, nivel-1, inclusive) + 1;
    }

    return mostrarNodosDesdeNivelContar(&(*pa)->izq, nivel-1, inclusive) + mostrarNodosDesdeNivelContar(&(*pa)->der, nivel-1, inclusive);
}


/** Funciones de ayuda */

int compararEnteros(const void * arg1, const void * arg2)
{
    int * dato1 = (int *) arg1, * dato2 = (int *)arg2;

    return *dato1-*dato2;
}

void mostrar(t_dato * d)
{
    printf("%d\n", *d);
}

/**En las Ciencias de la Computaci�n, se trata un subtipo de �rboles, los �rboles Binarios.
en su estructura de informaci�n, puede hacer referencia a lo sumo a dos sub�rboles diferenciados, el sub�rbol izquierdo y el sub�rbol derecho.
se puede tener un �rbol vac�o.
Se reconoce que habr� una referencia al nodo ra�z, y que esta no forma parte de la estructura de datos del �rbol Binario.
Esta referencia tendr� la direcci�n del nodo raiz, si este existe.
A partir de la raiz del �rbol, se tendr� un sub�rbol izquierdo y un sub�bol derecho que verifican recursivamente la definici�n.  Es decir que de existir sub�rbol izquierdo (y/o derecho), este puede ser vac�o o tener un nodo (raiz del sub�bol izquierdo/derecho), que puede tener sub�rbol izquierdo y/o derecho.
As� mismo compartimos que la raiz, de existir se encuentra en el nivel 0 (cero), y que los nodos (raices de sus sub�rboles izquierdo/derecho), de existir se encuentran en el nivel 1, y as� sucesivamente.
Los nodos que no tienen ninguno de sus sub�rboles derecho ni izquierdo, se denominan hojas.
profundidad de un �rbol, como el m�ximo nivel de alguna de sus hojas.
altura como uno m�s que el nivel,  la profundidad,  la hacen igual al nivel.
no se puede hablar de profundidad ni nivel de un �rbol vac�o.*/


/** precondici�n: �rbol NO VAC�O */
int profundidadArbol(t_arbol *p)
{
   if(*p)
   {
      int profIzq = profundidadArbol(&(*p)->izq),
          profDer = profundidadArbol(&(*p)->der);
      return profIzq > profDer ? profIzq + 1 : profDer + 1;
   }
   return -1; /* con �rbol vac�o devuelve -1 = ERROR: no deb�a utilizar esta primitiva */
}

/** sin precondici�n, devuelve cero cuando el �rbol est� vac�o */
/*int alturaArbol(t_arbol *p)
{
   if(*p)
   {
      int altIzq = alturaArbol(&(*p)->izq),
          altDer = alturaArbol(&(*p)->der);

      return altIzq > altDer ? altIzq + 1 : altDer + 1;
   }
   return 0; // con �rbol vac�o devuelve 0 = indicador de esta condici�n
}*/

/**En ambos casos vale el > o el >= en el condicional.

�rbol Binario Completo:
- Es un �rbol Binario en que todos sus nodos, salvo las hojas tienen sub�rbol por izquierda y tambi�n sub�rbol por derecha.  Es decir que es estrictamente binario.
- Adem�s todas sus hojas se encuentran al mismo nivel/alura/profundidad.

Con lo cual tiene 2 ^ (h - 1) - 1 nodos, o sea 2 ^ p - 1 nodos.

Teniendo en cuenta que las hojas estar�n a la altura m�xima ... lo que hablamos.*/
int arbolCompleto(t_arbol *p)
{
   int h = alturaArbol(p);
   return esCompleto(p, h);  /* invocando la funci'on que lo determina */
}

int esCompleto(t_arbol *p, int h)
{
   if(*p)
   {
      return esCompleto(&(*p)->izq, h - 1) && esCompleto(&(*p)->der, h - 1);
   }
   return h == 0;
}


/**�rbol Balanceado:  dado un �rbol de altura/profundidad dada es balanceado si comprende un �rbol completo de altura/profundidad con una altura/profundidad uno menos que la propia.*/

int arbolBalanceado(t_arbol *p)
{
   int h = alturaArbol(p);
   return esBalanceado(p, h);  /* invocando la funci'on que lo determina */
}

int esBalanceado(t_arbol *p, int h)
{
   if(*p)
   {
      return esBalanceado(&(*p)->izq, h - 1) && esBalanceado(&(*p)->der, h - 1);
   }
   return h <= 1;
}
