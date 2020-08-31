#include <stdio.h>
#include <stdlib.h>

//Ejercicio 14
//Comprueba si la fecha ingresada es formalmente correcta

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int comprobarFecha(tFecha);

int main()
{
    tFecha fecha;

    printf("Ingrese el numero de un dia: \n");
    scanf("%d", &fecha.dia);
    printf("Ingrese un numero de mes: \n");
    scanf("%d", &fecha.mes);
    printf("Ingrese un numero de anio: \n");
    scanf("%d", &fecha.anio);

    if (comprobarFecha(fecha))
        printf("La fecha %d/%d/%d es formalmente correcta. \n", fecha.dia, fecha.mes, fecha.anio);
    else
        printf("La fecha %d/%d/%d no es formalmente correcta. \n", fecha.dia, fecha.mes, fecha.anio);

    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
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
            if (fecha.anio % 4 == 0 || fecha.anio % 400 == 0) //¿Es el año bisiesto?
                return 1;
            else
                return 0;
        else
            return 0;
    }

    //Si paso todas las validaciones, retornamos 1
    return 1;
}
