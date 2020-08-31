#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char cad1[] = "mundo", cad2[] = "hola ";

    printf("RES: %s", strcat_inverso(cad1, cad2));
    return 0;
}
