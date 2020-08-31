#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    /** Son las 11:49, la hora de entrega era a las 11:45.
    Te fallé, Ritchie.

    De nuevo.
    */
    char cad[] = "Hola como estas";

    printf("Cadena normal: %s\n", cad);
    printf("Cadena invertida in-situ y codificada: %s", codificarInvertir(cad));
    return 0;
}
