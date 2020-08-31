#include "funciones.h"

/*  TIPS FUNCIONES RECURSIVAS:

    Nunca llamar a las funciones recursivas con n++, n--. No modificar la variable
    en la instancia actual.

    No usar for o whiles. La funcion tiene que ser recursiva.

    VENTAJAS Y DESVENTAJAS

    Ventajas de recursivas:
    -Mas facil de implementar en algunos casos

    Desventajas de recursivas:
    -Mas memoria
    -Mas tiempo de ejecucion

*/

int main()
{
    char cad[] = "hola";
    int num = 1234;

    /* Ejemplo de recursividad con factorial

    int numero;
    printf("Ingrese un numero entero para calcular su factorial: \n");
    scanf("%d", &numero);

    printf("El factorial de %d es %lf.", numero, factorial(numero));*/

    printf("MOSTRAR POR LINEA: \n");
    printf("*\n");
    mostrarPorLinea(cad);
    printf("*\n\n");

    printf("MOSTRAR POR LINEA INVERSO: \n");
    printf("*\n");
    mostrarPorLineaInverso(cad);
    printf("*\n\n");

    printf("MOSTRAR POR LINEA AMBOS: \n");
    printf("*\n");
    mostrarPorLineaAmbos(cad);
    printf("*\n\n");

    printf("MOSTRAR POR LINEA AMBOS SIN DUPLI: \n");
    printf("*\n");
    mostrarPorLineaAmbosSinDP(cad);
    printf("*\n\n");

    printf("MOSTRAR CADENA DECRECIENTE: \n");
    printf("*\n");
    mostrarCadenaDecreciente(cad);
    printf("*\n\n");

    printf("MOSTRAR CADENA CRECIENTE: \n");
    printf("*\n");
    mostrarCadenaCreciente(cad);
    printf("*\n\n");

    printf("MOSTRAR CADENA AMBOS: \n");
    printf("*\n");
    mostrarCadenaAmbos(cad);
    printf("*\n\n");

    printf("MOSTRAR CADENA AMBOS SIN DUPLI: \n");
    printf("*\n");
    mostrarCadenaAmbosSinDP(cad);
    printf("*\n\n");

    printf("MOSTRAR NUMERO POR LINEA: \n");
    printf("*\n");
    mostrarNumeroPorLinea(num);
    printf("*\n\n");

    printf("MOSTRAR NUMERO POR LINEA INVERSO: \n");
    printf("*\n");
    mostrarNumeroPorLineaInverso(num);
    printf("*\n\n");

    printf("MOSTRAR NUMERO ESCALONADO: \n");
    printf("*\n");
    mostrarNumeroEscalonado(num);
    printf("*\n\n");

    printf("MOSTRAR NUMERO ESCALONADO INVERSO: \n");
    printf("*\n");
    mostrarNumeroEscalonadoInverso(num);
    printf("*\n\n");

    printf("MOSTRAR NUMERO AMBOS: \n");
    printf("*\n");
    mostrarNumeroAmbos(num);
    printf("*\n\n");

    printf("MOSTRAR NUMERO AMBOS SIN DUPLI: \n");
    printf("*\n");
    mostrarNumeroAmbosSinDP(num);
    printf("*\n\n");

    return 0;
}
