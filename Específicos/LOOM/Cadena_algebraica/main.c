#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* Consigna

Desarrollar una función, que recibe una cadena de caracteres validada, la misma contiene expresiones algebraicas simples, de la forma:
nro1 (operación) nro2 (operación) nroN … =
nroX: es un número entero sin signo.
(operación) sólo puede ser + -
La expresión puede tener “n” términos.
El símbolo “=” siempre aparece al final de la cadena.
La función retorna el valor numérico de la expresión algebraica recibida.
*/

int main()
{
    char cadena[] = "300+90-5+54+100-100=";

    printf("EL RESULTADO ES %d ;)", calcularResultado(cadena));
    return 0;
}
