#include <utilitarias.h>

void texto_a_nota(const char * cadena, t_nota * pnota)
{
    sscanf(cadena, "%li %s %d", &pnota->dni, pnota->tipo, &pnota->nota);
}
