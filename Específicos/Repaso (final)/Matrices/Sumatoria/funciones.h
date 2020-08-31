#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

#define COL 100

int sumatoriaArribaDP(int mat[][COL], int fil, int col, int incluir);
int sumatoriaAbajoDP(int mat[][COL], int fil, int col, int incluir);
int sumatoriaArribaDS(int mat[][COL], int fil, int col, int incluir);
int sumatoriaAbajoDS(int mat[][COL], int fil, int col, int incluir);

#endif // FUNCIONES_H_
