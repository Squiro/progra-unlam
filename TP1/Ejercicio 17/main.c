#include <stdio.h>
#include <stdlib.h>

//Ejercicio 17
//Obtiene la fecha resultado de restarle X cant de dias.

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int comprobarFecha(tFecha);
int esBisiesto(tFecha);
tFecha restarleDias(tFecha, int);

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
        printf("Ingrese una cantidad de dias a restarle a la fecha: \n");
        scanf("%d", &cantDias);
        cantDias = abs(cantDias);
        fecha = restarleDias(fecha, cantDias);
        printf("La nueva fecha es %d/%d/%d. \n", fecha.dia, fecha.mes, fecha.anio);
    }
    else
        printf("La fecha %d/%d/%d no es formalmente correcta. \n", fecha.dia, fecha.mes, fecha.anio);

    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
}

tFecha restarleDias(tFecha fecha, int cantDias)
{
    //Como en cualquier lenguaje DECENTE, los arrays comienzan en 0.
    //Cada vez que querramos acceder a un mes, tenemos que tener la precaucion de restarle 1 al mes que nos dieron.
    int cantDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Comprobamos si el año es bisiesto y el mes es febrero
    if (esBisiesto(fecha) && fecha.mes == 2)
        cantDiasMes[1] = 29; //Cambiamos a 29 dias

    //Si al restarle los dias estos se vuelven negativos, lo tomamos en cuenta
    if (fecha.dia-cantDias <= 0)
    {
        //Restamos la cantidad actual de dias que transcurrieron
        cantDias -= fecha.dia;

        //Iteramos mientras la resta sea mayor a 0
        do
        {
            fecha.mes--;

            if (fecha.mes <= 0)
            {
                fecha.mes = 12;
                fecha.anio--; //Si pasamos el mes nro 12, aumentamos un año
            }
            cantDias -= cantDiasMes[fecha.mes-1];
        } while (cantDias > 0);

        fecha.dia = abs(cantDias);

    }
    else
        fecha.dia -= cantDias;


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
