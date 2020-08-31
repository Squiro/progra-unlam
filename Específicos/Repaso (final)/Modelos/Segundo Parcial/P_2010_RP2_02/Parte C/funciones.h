#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "fecha.h"
#include "arbol.h"

#define ERROR_ARCH 99

typedef struct
{
    long nroCta;
    char nombreTitular[30];
    t_fecha fch_alta;
    t_fecha fch_ult_mov;
    double saldo;
    char estado;
} t_cuenta;

int generarLote(char * ruta);
int darBajaInactivas(t_arbol *pa, char * ruta);
void modificarRegistro(FILE * arch, t_cuenta *cta);
int generarArchivo(t_arbol *pa, char * ruta);
int mostrarArchivo(char * ruta);

#endif // FUNCIONES_H_
