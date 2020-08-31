#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "lista_circ.h"

#define ERROR_ARCH 99

typedef struct
{
    long nroCliente;
    char * email;
    int nroSorteo;
} t_cliente;

int eliminarDeCola(t_arbol *pa, t_lista *pl, char * ruta);
void recorrer_inorden_eliminar(t_arbol *pa, t_lista *pl, FILE * arch);
void escribirEnArchivo(FILE * arch, t_indice * idx);
int mostrarArchivo(char * ruta);
void ingresarCliente(t_indice * idx);
char * ingresarCadena();
char * mi_strncpy(char *str, char * buffer, unsigned int limit);
#endif // FUNCIONES_H_
