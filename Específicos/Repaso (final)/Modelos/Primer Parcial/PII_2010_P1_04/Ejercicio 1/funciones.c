#include "funciones.h"

#include <math.h>

float calcularRaiz(float numero, float tolerancia)
{
    float termino = 1, terminoPrev = 0;

    do
    {
        terminoPrev = termino;
        termino = (terminoPrev+(numero/terminoPrev))/2;
    }   while (fabs(termino-terminoPrev) > tolerancia);

    return termino;
}
