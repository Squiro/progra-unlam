#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED
#include<stdio.h>
#include<arbol.h>
#include<cola.h>

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

void promedio_general(const t_arbol * pa);
void calcula_promedio_general(const t_arbol * pa, t_promedio * prom);
float calcula_promedio_alumno(const t_alumno* alu);
//void listar_ape_desc(const t_arbol * pa);

#endif // UTILITARIAS_H_INCLUDED
