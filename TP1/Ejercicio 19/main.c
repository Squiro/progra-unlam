#include <stdio.h>
#include <stdlib.h>

//Ejercicio 19
//Dada una fecha, indica el dia de la semana que le corresponde

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int comprobarFecha(tFecha);
int diasHastaFecha(tFecha, int);
int esBisiesto(tFecha);
int dayofweek(int, int, int);



int main()
{
    char *days[] = {"Domingo", "Lunes", "Martes", "Miercoles",
				"Jueves", "Viernes", "Sabado"};

    tFecha fecha;

    printf("Ingrese el dia de la fecha: ");
    scanf("%d", &fecha.dia);
    printf("\nIngrese el mes de la fecha: ");
    scanf("%d", &fecha.mes);
    printf("\nIngrese el anio de la fecha: ");
    scanf("%d", &fecha.anio);
    if (comprobarFecha(fecha))
    {
        printf("\nEl dia correspondiente a la fecha es %s.", days[dayofweek(fecha.anio, fecha.mes, fecha.dia)]);
        printf("\nPresione cualquier tecla para volver a ejecutar este programa.\n");
        getch();
        main();
    }
    else
    {
        printf("La fecha ingresada no corresponde a una fecha existente. Por favor reingrese la fecha. \n");
        main();
    }
    return 0;
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

//Este algoritmo fue publicado por Tomohiko Sakamoto en el grupo de grupo de noticias de Usenet comp.lang.c, en el año 1992.
//https://www.quora.com/How-does-Tomohiko-Sakamotos-Algorithm-work?redirected_qid=2169352

int dayofweek(y, m, d)	/* 1 <= m <= 12,  y > 1752 (in the U.K.) */
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
