#pragma once
#include <stdlib.h>
#include <stdio.h>

/* Lo primero que vemos es la raíz del arbol. La raíz es única.

    De la raízpueden salir ramas. De una rama pueden salir más ramas, hasta que encuentro
    una hoja. Todos los nodos terminales que me encuentre son hojas. Sin importar a qué altura estén.

    Una raíz puede ser una hoja si lo único que hay en el árbol es su raíz. Es un caso particular.

    -Grado del árbol: cantidad máxima de hijos que puede tener un padre.
    Un árbol de grado 1 es una lista (porque los nodos están uno atrás de otro).
    Los árboles binarios pueden tener a lo sumo dos hijos (0, 1, o 2, pero no más).
    Grado N: A lo sumo N hijos.

    A lo sumo pueden tener 1 padre (la raíz no tiene padre, por eso esta condición).

    -Grafo: serie/secuencia de nodos unidos por diferentes caminos. Es decir, los nodos pueden tener más
    de un padre. Un árbol es un caso particular de un grafo.

    Para encontrar al árbol, necesitamos un puntero a la raíz del árbol.

    Si no hay árbol la raíz vale nulo.

    -Nivel / altura de un árbol: la longitud máxima que tiene una rama que va desde la raíz hasta la hoja es el nivel.
    Altura = nivel + 1
    Si no existe nivel, la altura es 0. (Inicializamos nivel en -1);
    Profundidad es altura.

    -Arbol binario de expresión: sirven para representar una expresión matemática sin utilizar parentesis ni llaves.
    Sus hojas están compuestas por números.

    -Veces que paso por un nodo (max): grado del arbol + 1

    -Estructura del nodo: puntero a izquierda, dato, puntero a derecha. En las hojas los punteros a izq y der son nulos.

    -Recorridos:
        Preorden: primero proceso la raíz, después voy a la izquierda, y después a la derecha: R I D
        Inorden: I R D
        Posorden: I D R

    Trabajamos árboles en forma recursiva.
    También nos paramos en el puntero anterior que apunta a ese nodo para verlo. (similar a lista simple enlazada)

    Según lo que tenga que hacer, es mejor recorrer el árbol de cierta forma.

    ARBOLES BINARIOS DE BUSQUEDA

    1- No hay claves duplicadas.
    2-Menores que la clave van a la izquierda (m < clave ->izq)
    3-Mayores que la clave van a la derecha (M > clave ->der)


*/

#define SIN_MEM 99
#define DUPLICADO 98
#define ARBOL_VACIO 97
#define ERROR_ABRIR 96
#define NOT_FOUND 404
#define FOUND 1
#define SUCCESS 0

/*typedef struct
{
    int dni;
    char apyn[50];
    char sex;
} t_alumno;
*/

typedef int t_dato;

typedef void (*t_accion)(const void *);
typedef int(*t_cmp)(const void *, const void *);
typedef int(*t_cond)(const void *);

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * izq;
    struct s_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;


/** Primitivas */

void crearArbol(t_arbol *pa);
int arbolVacio(t_arbol *pa);
int arbolLLeno(t_arbol *pa);
int cortarHojas(t_arbol * pa);
int podarHastaNivel(t_arbol * pa, int nivel);
int podarHastaAltura(t_arbol * pa, int altura);
void eliminarArbol(t_arbol *pa);
int alturaArbol(const t_arbol * pa);
int esBalanceado(t_arbol *p, int h);
int arbolCompleto(t_arbol *p);
int esCompleto(t_arbol *p, int h);

int eliminar_de_arbol(t_arbol *pa, t_dato *d, t_cmp comparar);
int eliminar_raiz(t_arbol *pa);
t_arbol * buscarMenor (t_arbol * pa);
t_arbol * buscarMayor(t_arbol * pa);

/** Funciones recursivas */

void preOrden(const t_arbol * pa, t_accion accion);
void inOrden(const t_arbol * pa, t_accion accion);
void posOrden(const t_arbol * pa, t_accion accion);
int insertarClaveRecursivo(t_arbol * pa, const t_dato * d, t_cmp comparar);
int insertarBalanceado(t_arbol * pa, FILE * arch, int ini, int fin, t_cmp comparar);

/** Funciones iterativas */

int preOrdenIterativo(t_arbol * pa, t_accion accion);
int inOrdenIterativo(t_arbol * pa, t_accion accion);
int posOrdenIterativo(t_arbol * pa, t_accion accion);
int insertarClaveIterativo(t_arbol * pa, const t_dato * d, t_cmp comparar);

/** Busqueda de claves iterativas */

int existeClave(t_arbol *pa, const t_dato *d, t_cmp comparar);
t_nodo * hallarDirClave(t_arbol *pa, t_dato *d, t_cmp comparar);
t_nodo * hallarDirPadreClave(t_arbol *pa, t_dato *d, t_cmp comparar);

/** Busquedas de claves recursivas */
int hallarNodo(const t_arbol * pa, t_dato * d, t_cmp comparar);
void buscarClaveMayor(const t_arbol * pa, t_dato * dato);
void buscarClaveMayor(const t_arbol * pa, t_dato * dato);
//t_dato buscarNodoClaveMayor(const t_arbol * pa);
//int buscarNodoClaveMayor(const t_arbol *pa, t_dato * d, t_cmp comparar);
//t_dato buscarNodoClaveMenor(const t_arbol * pa);
//int buscarNodoClaveMenor(const t_arbol * pa, t_dato * d, t_cmp comparar);

t_dato buscarNodoMayorDato(const t_arbol *pa);
t_dato buscarNodoMenorDato(const t_arbol *pa);

/** Guardar y recuperar preorden */
void guardar_arbol_bin(const t_arbol* pa, FILE* arch);
void guardar_arbol_txt(const t_arbol* pa, FILE* arch);
void leer_bin_preorden(t_arbol * pa, FILE * arch, t_cmp comparar);

/** Contar nodos y cosas */

int contarNodos(const t_arbol * pa);
int contarHojas(const t_arbol * pa);
int contarNoHojas(const t_arbol * pa);
int contarCondicion(const t_arbol * pa, t_cond condicion);
int contarNodosSubarbolDerecho(const t_arbol * pa);
int contarHijosIzq(const t_arbol * pa);
int contarHijosDer(const t_arbol * pa);
int contarHijosSoloIzq(const t_arbol * pa);
int contarHijosSoloDer(const t_arbol * pa);

/** Mostrar nodos y cosas */

void mostrarNodosEnNivel(const t_arbol * pa, int nivel);
void mostrarNodosEnAltura(const t_arbol * pa, int altura);
void mostrarNodosHastaNivel(const t_arbol *pa, int nivel, int inclusive);
void mostrarNodosDesdeNivel(const t_arbol *pa, int nivel, int inclusive);


/** Funciones de ayuda */
void mostrar();
int compararEnteros(const void * arg1, const void * arg2);
int es_par(const void * num);
