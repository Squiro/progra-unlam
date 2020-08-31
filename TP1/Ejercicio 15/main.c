#include <stdio.h>
#include <stdlib.h>

//Ejercicio 15
//Obtiene la fecha del dia siguiente a la ingresada

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int comprobarFecha(tFecha);
int esBisiesto(tFecha);
tFecha sumarleDias(tFecha, int);

int main()
{
    tFecha fecha;
    int cantDias;

    printf("Ingrese el numero de un dia: \n");
    scanf("%d", &fecha.dia);
    printf("Ingrese un numero de mes: \n");
    scanf("%d", &fecha.mes);
    printf("Ingrese un numero de anio: \n");
    scanf("%d", &fecha.anio);

    if (comprobarFecha(fecha))
    {
        fecha = sumarleDias(fecha, 1);
        printf("La fecha del dia siguiente es es %d/%d/%d. \n", fecha.dia, fecha.mes, fecha.anio);
    }
    else
        printf("La fecha %d/%d/%d no es formalmente correcta. \n", fecha.dia, fecha.mes, fecha.anio);

    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
}

tFecha sumarleDias(tFecha fecha, int cantDias)
{
    //Como en cualquier lenguaje DECENTE, los arrays comienzan en 0.
    //Cada vez que querramos acceder a un mes, tenemos que tener la precaucion de restarle 1 al mes que nos dieron.
    int cantDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Comprobamos si el año es bisiesto y el mes es febrero
    if (esBisiesto(fecha) && fecha.mes == 2)
        cantDiasMes[1] = 29; //Cambiamos a 29 dias

    //Si al sumarle dias la fecha sobre pasa la cant de dias del mes, lo tomamos en cuenta
    if (fecha.dia+cantDias > cantDiasMes[fecha.mes-1])
    {
        //Como la suma sobrepaso la cantidad de dias del mes, significa que hubo un cambio de mes
        //Tenemos que cambiar adecuadamente el numero de meses
        cantDias -= cantDiasMes[fecha.mes-1] - fecha.dia;

        //Iteramos mientras la resta sea mayor a 0
        do
        {
            fecha.mes++;
            cantDias -= cantDiasMes[fecha.mes-1];
            if (fecha.mes > 12)
            {
                fecha.mes = 1;
                fecha.anio++; //Si pasamos el mes nro 12, aumentamos un año
            }

        } while (cantDias > 0);

        fecha.dia = cantDiasMes[fecha.mes-1] - abs(cantDias);
        //fecha.mes = mes;
    }
    else
        fecha.dia += cantDias;


    return fecha;
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
