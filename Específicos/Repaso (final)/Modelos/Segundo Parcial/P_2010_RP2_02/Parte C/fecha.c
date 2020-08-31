#include "fecha.h"

int ingresarFecha(t_fecha *fec)
{
    ingresarDia(fec);
    ingresarMes(fec);
    ingresarAnio(fec);

    if (!validarFecha(fec))
    {
        fprintf(stderr, "La fecha ingresada es erronea");
        exit(1);
    }

    return TODO_OK;
}

void ingresarDia(t_fecha *fec)
{
    do
    {
        printf("\nIngrese el dia: ");
        scanf("%d", &fec->dia);
    } while (fec->dia <= 0 || fec->dia > 31);
}

void ingresarMes(t_fecha *fec)
{
    do
    {
        printf("\nIngrese el mes: ");
        scanf("%d", &fec->mes);
    } while (fec->mes <= 0 || fec->mes > 12);
}

void ingresarAnio(t_fecha *fec)
{
    do
    {
        printf("\nIngrese el anio: ");
        scanf("%d", &fec->anio);
    } while (fec->anio <= 0);
}

int validarFecha(t_fecha *fec)
{
    static const char dias[][12] = {
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    };

    return fec->dia <= dias[esBisiesto(fec->anio)][fec->mes-1];
}

int esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

int compararFechas(const t_fecha * fec1, const t_fecha  * fec2)
{
    int cmp = fec1->anio - fec2->anio;

    if (cmp)
        return cmp;
    cmp = fec1->mes - fec2->mes;
    if (cmp)
        return cmp;
    return fec1->dia - fec2->dia;
}
