#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "datos.h"
#define MAYOR(X,Y) (X)>(Y)?(X):(Y)
#define ES_HOJA !(*pa)->izq&&!(*pa)->der
#define SIN_MEM 0
#define DUPLICADO 0
#define ARBOL_VACIO 0
#define ERROR_LECTURA 0
#define ERROR_ARCHIVO 3
#define ERROR_ARBOL 2
#define OK 1

typedef struct s_nodoa
{
    t_info info;
    struct s_nodoa *izq;
    struct s_nodoa *der;
}t_nodoa;

typedef t_nodoa *t_arbol;

void crear_arbol(t_arbol *);
int arbol_lleno(const t_arbol *);
int arbol_vacio(const t_arbol *);
int insertar_arbol_enorden(t_arbol *,const t_info *,int(*cmp)(const void *,const void*));
int contar_nodos(const t_arbol *);
t_arbol *obtener_mayor(const t_arbol *);
t_arbol *obtener_menor(const t_arbol *);
t_info obtener_mayor_elemento(const t_arbol *,void (*accion)(const t_info*,void*));
t_info obtener_menor_elemento(const t_arbol *,void (*accion)(const t_info*,void*));
int contar_hasta_nivel(const t_arbol *,int n);
int completo_hasta_nivel(const t_arbol *,int n);
int arbol_avl(const t_arbol *);
int altura_arbol(const t_arbol *);
void recorrer_en_orden(const t_arbol *,void *,void(*accion)(const t_info *,void *));
void recorrer_preorden(const t_arbol *,void *,void (*accion)(const t_info*,void*));
int eliminar_arbol(t_arbol *,t_info *,int(*cmp)(const void *,const void *));
t_arbol *buscar_nodo(const t_arbol *,t_info *,int(*cmp)(const void *,const void *));
int eliminar_raiz(t_arbol *);
void vaciar_arbol(t_arbol *);
void podar_hojas_arbol(t_arbol *);
void podar_hojas_desde_nivel(t_arbol *,int);



#endif // ARBOL_H_INCLUDED
