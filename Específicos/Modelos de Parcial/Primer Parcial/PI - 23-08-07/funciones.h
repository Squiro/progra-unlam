#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

/** Ejercicio 1 */
#define TAM 100

int contarCaracteres(char *cadena);

char * invertirCadena(char *cadena);

void triangularInferior(int mat[][TAM], int tam);

/** Ejercicio 2 */
#define ERROR_ABRIR 99

/** Parte A */

typedef struct
{
    char cod[10];
    char marca[10];
    char modelo[10];
    int anio;
    double precio;

} t_moto;

int generarLote();

int incrementarPrecio();

int actualizarRegistros(int anio);

int mostrarArchivo();

/** Parte B */

#define SIN_MEM 98
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);

typedef t_moto t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

/** Inicializa la lista en nulo */
void crearLista(t_lista *pl);

/** Inserta siempre al principio */
int insertarPrincipio(t_lista *pl, const t_dato *d);

/** Inserte siempre al final */
int insertarFinal(t_lista *pl, const t_dato *d);

int ordenarLista(t_lista *pl, t_cmp comparar);

void * hallarMenor(t_lista *pl, t_cmp comparar);

int compararMotos(const void * arg1, const void * arg2);

int mi_strcmp(const char * str1, const char * str2);

int guardarEnLista(t_lista *pl);

void mostrarLista(t_lista *pl);

/** Parte C */

int quitarMarca(t_lista *pl);

void mostrarMayoresA(t_lista *pl, double precio);
#endif // FUNCIONES_H_
