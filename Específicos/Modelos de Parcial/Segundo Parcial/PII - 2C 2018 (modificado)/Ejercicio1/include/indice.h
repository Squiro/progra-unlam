#ifndef INDICE_H_
#define INDICE_H_

#include <tipos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbol_indice.h"

int crearIndice(t_arbol_indice * pa, const char * path, const char * rutaIdx);
void generarArchivoIndice(t_arbol_indice * pa, FILE * arch);
int mostrarIndice(const char * rutaIdx);
int compararNombres(const t_indice *info1, const t_indice *info2);

int listar_ape_desc(const char * path, const char * rutaIdx);

#endif // INDICE_H_



