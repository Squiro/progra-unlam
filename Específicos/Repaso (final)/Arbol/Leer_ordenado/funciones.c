#include "funciones.h"

int generarLote(char * ruta)
{
    FILE * arch;
    t_empleado emps[3] = { { 1, "Jose", 250 }, { 2, "Martin", 225 }, { 3, "Martina", 230 } };
    int i;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    for (i = 0; i < 3; i++)
        fwrite(&emps[i], sizeof(t_empleado), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int generarArbol(t_arbol *pa, char * ruta)
{
    FILE * arch;
    int tam;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

    fseek(arch, 0, SEEK_END);
    tam = ftell(arch)/sizeof(t_empleado)-1;

    leerEnOrden(pa, arch, 0, tam, compararDNI);

    return SUCCESS;
}
