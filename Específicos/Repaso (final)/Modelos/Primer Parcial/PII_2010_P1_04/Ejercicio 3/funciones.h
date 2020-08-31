#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "lista_simp.h"

#define ERROR_ARCH 99

int generarLote(char * ruta);
int guardarEnLista(t_lista * pl, char * ruta);
int guardarListaEnArchivo(t_lista * pl, char * ruta);
int mostrarArchivo(char * ruta);

#endif // FUNCIONES_H_
