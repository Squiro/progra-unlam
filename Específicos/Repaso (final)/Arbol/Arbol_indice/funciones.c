#include "funciones.h"

int generarLote(char * ruta)
{
    int i;
    FILE * arch;
    t_empleado emps[4] = { { 2, "Jose", 223 }, { 1, "Martin", 409 }, { 9, "Martina", 230 }, { 4, "Martino", 200 } };

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    for (i = 0; i < 4; i++)
        fwrite(&emps[i], sizeof(t_empleado), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int guardarIndiceEnArbol(t_arbol *pa, char * ruta)
{
    FILE * arch;
    long count = 0;
    t_indice idx;
    t_empleado emp;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;


    fread(&emp, sizeof(t_empleado), 1, arch);

    while (!feof(arch))
    {
        idx.dni = emp.dni;
        idx.numReg = count;
        insertar(pa, &idx, compararEnteros);
        count++;
        fread(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int generarArchivoIndice(t_arbol *pa, char *rutaIdx)
{
    FILE * arch;

    arch = fopen(rutaIdx, "wb");

    if (!arch)
        return ERROR_ARCH;

    escribirArchivoIndice(pa, arch);

    fclose(arch);

    return SUCCESS;
}

void escribirArchivoIndice(t_arbol *pa, FILE * arch)
{
    if (*pa)
    {
        escribirArchivoIndice(&(*pa)->izq, arch);
        fwrite(&(*pa)->dato, sizeof(t_indice), 1, arch);
        escribirArchivoIndice(&(*pa)->der, arch);
    }
}

int ordenarArchivo(char *rutaEmp, char * rutaIdx, char *rutaRes)
{
    FILE *archEmp, * archIdx, * archRes;
    t_indice idx;
    t_empleado emp;

    archEmp = fopen(rutaEmp, "rb");

    if (!archEmp)
        return ERROR_ARCH;

    archIdx = fopen(rutaIdx, "rb");

    if (!archIdx)
    {
        fclose(archEmp);
        return ERROR_ARCH;
    }

    archRes = fopen(rutaRes, "wb");

    if (!archRes)
    {
        fclose(archEmp);
        fclose(archIdx);
        return ERROR_ARCH;
    }

    fread(&idx, sizeof(t_indice), 1, archIdx);

    while (!feof(archIdx))
    {
        fseek(archEmp, idx.numReg*sizeof(t_empleado), SEEK_SET);
        fread(&emp, sizeof(t_empleado), 1, archEmp);
        fwrite(&emp, sizeof(t_empleado), 1, archRes);
        fread(&idx, sizeof(t_indice), 1, archIdx);
    }

    fclose(archEmp);
    fclose(archIdx);
    fclose(archRes);

    return SUCCESS;
}

int mostrarArchivo(char * ruta)
{
    FILE * arch;
    t_empleado emp;

    arch = fopen(ruta, "rb");

    fread(&emp, sizeof(t_empleado), 1, arch);

    while (!feof(arch))
    {
        printf("\nDNI: %d", emp.dni);
        printf("\nNombre: %s", emp.apyn);
        printf("\nSueldo: %0.2lf", emp.sueldo);
        printf("\n\n");
        fread(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

