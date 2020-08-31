#include "colagen.h"

int main()
{
    //El usuario no tiene que conocer la estructura de la cola
    //t_cola cola = { sizeof(int), NULL, NULL };
    t_cola cola,

    int x = 10, tope;

    crearCola(&cola, sizeof(int));
    acolar(&cola, &x);
    verTope(&cola, &tope);
    printf("El tope es: %d", tope);
    return 0;
}
