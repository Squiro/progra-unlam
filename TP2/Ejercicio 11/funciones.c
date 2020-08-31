#include "funciones.h"

int generarLote()
{
    int i;
    FILE * arch;

    arch = fopen("datos.txt", "w");

    if (!arch)
    {
        printf("No se pudo abrir el archivo.");
        return ERROR_ABRIR;
    }

    for (i = 0; i < 5; i++)
        fprintf(arch, "%d\n", rand());

    fclose(arch);

    //Sobreescribimos el archivo de esMayorA
    arch = fopen("esMayorA100.txt", "w");
    fclose(arch);


    return 0;
}

int leerLote()
{
    char cadena[100];
    int multi_5 = 0, multi_6 = 0, multi_11 = 0;
    FILE * arch;

    arch = fopen("datos.txt", "r");

    if (!arch)
    {
        printf("No se pudo abrir el archivo.");
        return ERROR_ABRIR;
    }

    fscanf(arch, "%s", &cadena);
    //fgets(cadena, 100, arch);

    while (!feof(arch))
    {
        if(esMultiplo5(cadena))
            multi_5++;
        if(esMultiplo6(cadena))
            multi_6++;
        if(esMultiplo11(cadena))
            multi_11++;
        if(esMayorA(cadena, 100))
            guardarArchivo("esMayorA100.txt", cadena);
        fscanf(arch, "%s", &cadena);
    }

    fclose(arch);

    printf("Hay %d multiplos de 5, %d multiplos de 6, y %d multiplos de 11.\n", multi_5, multi_6, multi_11);

    return 0;
}

//Su último digito debe ser 0 o 5
int esMultiplo5(char *cadena)
{
    while (*cadena)
        cadena++;

    cadena--;

    if (*cadena - '0' == 5 || *cadena - '0' == 0)
        return 1;
    else
        return 0;
}

//Debe ser par, y la suma de sus digitos debe ser multiplo de 3
int esMultiplo6(const char *cadena)
{
    int acum = 0;

    //Si no es par, descartamos que sea multiplo de 6
    if (atoi(cadena) % 2 != 0)
        return 0;

    while (*cadena)
    {
        acum += *cadena - '0';
        cadena++;
    }

    if (acum % 3 == 0)
        return 1;
    else
        return 0;
}

//Es multiplo de 11 si la suma de las posiciones de digitos pares e impares son multiplos de once
int esMultiplo11(char *cadena)
{
    char *pLec = cadena;

    int posPares = 0, posImpares = 0;

    while (*pLec)
    {
        posPares += *pLec - '0';
        pLec+=2;
    }

    if (posPares % 11 != 0)
        return 0;

    pLec = cadena;
    while (*pLec)
    {
        posImpares += *pLec - '0';
        pLec+=2;
    }

    if (posImpares % 11 != 0)
        return 0;

    return 1;
}

int esMayorA(const char *cadena, int num)
{
    if (atoi(cadena) > num)
        return 1;
    else
        return 0;
}

int guardarArchivo(char *ruta, const char *cadena)
{
    FILE * arch;

    arch = fopen(ruta, "a+");

    if (!arch)
    {
        printf("No se pudo abrir el archivo,");
        return ERROR_ABRIR;
    }

    fprintf(arch, "%s\n", cadena);

    fclose(arch);

    return 0;
}
