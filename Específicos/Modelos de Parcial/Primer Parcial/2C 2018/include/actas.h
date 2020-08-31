#ifndef ACTAS_H_INCLUDED
#define ACTAS_H_INCLUDED

#include <tipos.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void generar_acta(const char * path_alus, const char * arch_notas, const char * arch_acta, const char * arch_obs);

/** Cambiada la declaracion de de la funcion para que sea más entendible

void generar_acta_res(const char * path_alus, const char * arch_notas, const char * arch_acta, const char * arch_obs); */

void generar_acta_res(const char * path_alum, const char * path_notas, const char * path_acta, const char * path_obs);

void calcular_nota_final_res(t_acta *a);
void calcular_nota_final(t_acta *a);

void validar_nota_final_res(const t_acta *a, FILE * arch_obs);
void validar_nota_final(const t_acta *a, FILE * arch_obs);

int buscar_alumno(long dni, t_alumno * alum, FILE * arch);

/** Inicializa el acta seteando en 0 las notas, y seteando a dni según lo que reciba por parámetro */
void inicializarActa(t_acta *acta, long dni);

int mismo_grupo(int p1, int p2);

int compararActas(const void * arg1, const void * arg2);

void handle_error(int err);

#endif // ACTAS_H_INCLUDED
