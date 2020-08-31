#include <stdio.h>
#include <stdlib.h>

//Ejercicio 18
//A partir de dos fechas, obtiene la cantidad de dias entre ellas

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int comprobarFecha(tFecha);
int difereciaEntreFechas(tFecha, tFecha, int);
int diasHastaFecha(tFecha, int);
int esBisiesto(tFecha);

int main()
{
    tFecha fechaA, fechaB;

    printf("Ingrese el dia de la fecha inicial: ");
    scanf("%d", &fechaA.dia);
    printf("\nIngrese el mes de la fecha inicial: ");
    scanf("%d", &fechaA.mes);
    printf("\nIngrese el anio de la fecha inicial: ");
    scanf("%d", &fechaA.anio);
    if (comprobarFecha(fechaA))
    {
        printf("\nIngrese el dia de la fecha final: ");
        scanf("%d", &fechaB.dia);
        printf("\nIngrese el mes de la fecha final: ");
        scanf("%d", &fechaB.mes);
        printf("\nIngrese el anio de la fecha final: ");
        scanf("%d", &fechaB.anio);
        if (comprobarFecha(fechaB))
            printf("La diferencia de dias entre ambas fechas es de: %d dias", difereciaEntreFechas(fechaA, fechaB, (fechaA.anio > fechaB.anio)?fechaB.anio:fechaA.anio));

        else
        {
            printf("La fecha ingresada no corresponde a una fecha existente. Por favor reingrese ambas fechas. \n");
            main();
        }
    }
    else
    {
        printf("La fecha ingresada no corresponde a una fecha existente. Por favor reingrese ambas fechas. \n");
        main();
    }
    return 0;
}

//Retorna un entero que significa la cantidad de días de diferencia que tienen ambas fechas
int difereciaEntreFechas(tFecha fechaA, tFecha fechaB, int anioReferencia)
{
    /*printf("\nDIAS CONTADOS: %d", diasHastaFecha(fechaA));
    printf("\nDIAS CONTADOS: %d", diasHastaFecha(fechaB));*/
    return abs(diasHastaFecha(fechaA, anioReferencia) - diasHastaFecha(fechaB, anioReferencia));
}

int diasHastaFecha(tFecha fecha, int anioReferencia)
{
    int contador = 0, mes = 1, anio = anioReferencia;
    int cantDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(fecha))
        cantDiasMes[1] = 29;

    while (anio != fecha.anio)
    {
        contador += cantDiasMes[mes-1];
        mes++;

        if (mes > 12)
        {
            mes = 1;
            anio++;
        }
    }

    while (mes != fecha.mes)
    {
        contador += cantDiasMes[mes-1];
        mes++;
    }

    contador += fecha.dia -1;

    return contador;
}

int comprobarFecha(tFecha fecha)
{
    //Comprobamos limites maximos y minimos
    if (fecha.dia <= 0 || fecha.mes <= 0 || fecha.anio <= 0 || fecha.dia > 31 || fecha.mes > 12)
        return 0;

    int cantDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //¿La fecha es mayor a la cantidad de dias que tiene el mes?
    if (cantDiasMes[fecha.mes-1] < fecha.dia)
    {   //¿Es el mes febrero? ¿Es el dia 29?
        if (fecha.mes == 2 && fecha.dia == 29)
            return esBisiesto(fecha);
        else
            return 0;
    }

    //Si paso todas las validaciones, retornamos 1
    return 1;
}

int esBisiesto(tFecha fecha)
{
    if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0) //¿Es el año bisiesto?
        return 1;
    else
        return 0;
}

