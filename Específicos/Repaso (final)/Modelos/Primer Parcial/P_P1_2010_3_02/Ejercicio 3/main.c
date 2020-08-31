#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char str[] = "HOLA HOLA PA TI MI COLA";
    printf("Count: %d", eliminarCaracteres(str, 'A'));
    printf("%s", str);
    return 0;
}
