#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "lista_simp.h"

int almacenarCadenas(char * mat[20]);
void anularMatriz(char * mat[20]);
char * ingresarCadena();
char * mi_strncpy(char * str1, const char *str2, int limit);
int chequearMayor(char *str1, char * str2);
int mi_strlen(const char *str);
int mi_strcmp(const char *str1, const char *str2);
void mostrarCadenas(char * mat[20]);
void guardarEnLista(t_lista *pl, char * mat[20]);
int compararCadenas(const void *arg1, const void *arg2);
int mostrarLista(t_lista *pl);
#endif // FUNCIONES_H_
