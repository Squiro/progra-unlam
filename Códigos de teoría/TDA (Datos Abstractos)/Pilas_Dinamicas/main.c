#include "piladin.h"

/*Las pilas tienen que tener el mismo tipo de dato, no puedo tener una pila con t_empleado y usar t_dato
y otra que sea t_estudiante usando t_dato*/

int main()
{
    int x = 10, y = 0;
    t_pila pila;

    crearPila(&pila);
    apilar(&pila, &x);
    verTope(&pila, &y);
    printf("%d", y);
    return 0;
}
