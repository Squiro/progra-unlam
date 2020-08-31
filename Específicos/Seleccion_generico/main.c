#include "funciones.h"

int main()
{
    int vec[] = {2, 9, 7, 15, 56, 95, 15};

    seleccion(vec, 7, sizeof(int), compararEnteros);
    mostrarVector(vec, 7);
    return 0;
}
