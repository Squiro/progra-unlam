#ifndef ARBOL_INDICE_H_
#define ARBOL_INDICE_H_

/** ¿Por qué creé esto? Porque arbol.h trabaja con el tipo de dato t_alumno. En el enunciado del parcial me pide que
    las opciones que venían por defecto sigan trabajando con el índice original. Si yo modifico el tipo de dato que utiliza
    el índice actual y lo cambio por la estructura t_indice, muchas de esas opciones no van a funcionar.

    Al menos ese es el razonamiento al que llego luego de haber hecho la modificación y de ver cómo me metía en una encrucijada
    de tipos de datos.
*/

#include <Tipos.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct i_nodo_arbol
{
	t_indice idx; /** El tipo definido en tipos.h **/
	struct i_nodo_arbol* pizq;
	struct i_nodo_arbol* pder;
}
t_nodo_arbol_indice;


typedef t_nodo_arbol_indice * t_arbol_indice;

typedef int (*t_comp)(const t_indice *, const t_indice *);

typedef void (*t_acc)(t_indice* idx, void* datos_accion);

typedef void (*t_mostrar_clave)(const t_alumno *);


void crear_arbol_indice(t_arbol_indice * pa);
int insertarEnArbolIndice(t_arbol_indice * pa, const t_indice* pd, t_comp comparar); ///Retorna TODO_OK, DUPLICADO O SIN_MEM

/** Funciones mias */
void recorrer_arbol_enorden_inverso(const t_arbol_indice * pa, t_acc accion, void* datos_accion);
void mostrar(t_indice* idx, void* datos_accion);

#endif // ARBOL_INDICE_H_
