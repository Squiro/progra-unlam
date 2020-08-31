#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*  En realidad esto no es un modelo que haya dado Renata. Esto es un parcial que tomó
    antes que el nuestro, y lo conseguimos de contrabando.

    Los puntos a hacer son:

    1. Comparar si una matriz es simétrica respecto a su eje central.

    2. Comparar si un string tiene el formato de una patente indicado. El formato es:

        Primera letra A mayúscula. Segunda letra puede ser B, C, o D mayúsculas. Luego siguen 3 digitos. Luego sigue una letra mayúscula cualquiera.
         (i.e): A(BCD)000(A-Z)

    3. Dos archivos de texto. Cada uno contiene un polinomio. Se debe crear un archivo nuevo que contenga el resultado de la sunma de los dos, de la siguiente
        forma:

        P(X)
        +
        Q(X)
        =
        RESULTADO(X)

        Hay que considerar el peor de los casos: que P(X) y Q(X) estén desordenados y sean de distinto grado c/u, y que además a alguno le falten miembros.
*/

int main()
{
    calcularSumaPolinomios();
    return 0;
}
