#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>
#include<cola.h>
#define NO_ABIERTO -1
typedef struct s_nodos
{
    t_info info;
   struct s_nodos * sig;
}t_nodo_l;

typedef t_nodo_l * t_lista;

void crear_lista(t_lista * );
void vaciar_lista(t_lista *);

int comparar_ap(const void *,const void *);
typedef int(*t_comp)(const void * ,const void *);
void mostrar_lista_desc(const t_lista *pl);
void mostrar_lista_asc(const t_lista *pl);

typedef void(*t_tipo)(const t_lista *);
int insertar_en_lista_ordenada(t_lista *,const t_alumno *,t_comp);
int listar_por_apellido(t_tipo);
void listar_por_apellido_indice(const t_arbol * pa,t_tipo mostrar);
void mejor_promedio(t_alumno * dato);






int alta_res (int dni, t_arbol* pa);
int alta (int dni, t_arbol* pa);

int baja_res (int dni, t_arbol* pa);
int baja (int dni, t_arbol* pa);

int baja_masiva_res (t_arbol* pa, t_cola*pc);
int baja_masiva (t_arbol* pa, t_cola *pc);

int cargar_bajas_masiva_res (t_cola* pc);
int cargar_bajas_masiva (t_cola* pc);

void ingresar_alumno_res(t_alumno* alu, int dni); ///Completa la carga del alumno (debe estar ya seteado el dni)
void ingresar_dni_alumno_res(t_alumno* alu); ///Ingresa el dni para el alumno
void imprimir_alumno_res(t_alumno* alu,void* datos);
void mostrar_dni_res(const t_alumno* r);
float calcula_promedio_alumno_res(const t_alumno* alu);

void imprimir_listado_res(const t_arbol *pa);
void imprimir_listado(const t_arbol *pa);

void validar_arbol_res(const t_arbol *pa);///Imprime si el arbol es completo, balanceado, AVL o ninguna
void validar_arbol(const t_arbol *pa);

void mayor_promedio_res(const t_arbol *pa);
void mayor_promedio(const t_arbol *pa);

#endif // UTILITARIAS_H_INCLUDED
