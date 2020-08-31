#include "funciones.h"

int main()
{
    char str1[] = "CASA BLANCA, BLANCA CASA", str2[] = "ANCA";
    char cad[] = "Algo que se me ocurrio", cad2[] = "aeiou";
    printf("%s\n", subcadena(str1, str2));
    printf("%d", eliminarCaracteres(cad, cad2));
    return 0;
}
