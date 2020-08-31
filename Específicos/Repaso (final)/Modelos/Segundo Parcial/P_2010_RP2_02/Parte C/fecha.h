#ifndef FECHA_H_
#define FECHA_H_

#include <stdlib.h>
#include <stdio.h>

#define TODO_OK 1

typedef struct
{
    unsigned int dia,
             mes,
             anio;
} t_fecha;

int ingresarFecha(t_fecha *fec);
void ingresarDia(t_fecha *fec);
void ingresarMes(t_fecha *fec);
void ingresarAnio(t_fecha *fec);
int validarFecha(t_fecha *fec);
int esBisiesto(int anio);
int compararFechas(const t_fecha * fec1, const t_fecha  * fec2);

#endif // FECHA_H_
