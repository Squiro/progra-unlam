#include <stdio.h>
#include <stdlib.h>

/*
    Tipo de dato para la fecha, los miembros 'struct' podrian estar en otro orden.
    La estructura no tiene existencia, ni ocupa lugar en memoria, si no es usada.

*/

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

int main()
{
    printf("Hello world!\n");
    return 0;
}
