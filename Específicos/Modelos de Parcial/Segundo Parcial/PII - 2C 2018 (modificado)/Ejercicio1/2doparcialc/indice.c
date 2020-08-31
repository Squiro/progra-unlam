#include "indice.h"
#include <utilitarias.h>

int crearIndice(t_arbol_indice * pa, const char * path, const char * rutaIdx)
{
    FILE * arch, * archIdx;
    t_alumno alum;
    t_indice idx;
    int count = 0;

    arch = fopen(path, "rb");

    if (!arch)
        return ERROR_ARCHIVO;

    fread(&alum, sizeof(t_alumno), 1, arch);

    while (!feof(arch))
    {
        strcpy(idx.apyn, alum.apyn);
        idx.numReg = count;
        //printf("IDX: %s %d\n", idx.apyn, idx.numReg);
        insertarEnArbolIndice(pa, &idx, compararNombres);
        count++;
        fread(&alum, sizeof(t_alumno), 1, arch);
    }

    fclose(arch);

    archIdx = fopen(rutaIdx, "wb");

    if (!archIdx)
        return ERROR_ARCHIVO;

    generarArchivoIndice(pa, arch);

    fclose(archIdx);

    //mostrarIndice(rutaIdx);

    return TODO_OK;
}

//Recorro en inorden, I R D
void generarArchivoIndice(t_arbol_indice * pa, FILE * arch)
{
    if (*pa)
    {
        generarArchivoIndice(&(*pa)->pizq, arch);
        fwrite(&(*pa)->idx, sizeof(t_indice), 1, arch);
        generarArchivoIndice(&(*pa)->pder, arch);
    }
}

int mostrarIndice(const char * rutaIdx)
{
    FILE * arch;
    t_indice idx;
    arch = fopen(rutaIdx, "rb");

    if (!arch)
        return ERROR_ARCHIVO;

    fread(&idx, sizeof(t_indice), 1, arch);

    while (!feof(arch))
    {
        printf("Nombre: %s", idx.apyn);
        printf("\nNumReg: %d", idx.numReg);
        printf("\n\n");
        fread(&idx, sizeof(t_indice), 1, arch);
    }

    fclose(arch);

    return TODO_OK;
}

int compararNombres(const t_indice *info1, const t_indice *info2)
{
    return strcmp(info1->apyn, info2->apyn);
}

int listar_ape_desc(const char * path, const char * rutaIdx)
{
    FILE * archAlum, * archIdx;
    t_indice idx;
    t_alumno alum;
    int tam, i;

    archAlum = fopen(path, "rb");

    if (!archAlum)
        return ERROR_ARCHIVO;

    archIdx = fopen(rutaIdx, "rb");

    if (!archIdx)
    {
        fclose(archAlum);
        return ERROR_ARCHIVO;
    }

    fseek(archIdx, 0, SEEK_END);
    tam = ftell(archIdx)/sizeof(t_indice);

    tam -= 1;
    fseek(archIdx, tam*sizeof(t_indice), SEEK_SET);
    fread(&idx, sizeof(t_indice), 1, archIdx);

    while (tam > -1)
    {
        fseek(archAlum, idx.numReg * sizeof(t_alumno), SEEK_SET);
        fread(&alum, sizeof(t_alumno), 1, archAlum);

        printf("DNI: %d\n", alum.dni);
        printf("Apellido y Nombre: %s\n", alum.apyn);
        printf("Notas: ");
        for (i = 0; i < alum.cant_materias; i++)
            printf("-%d ", alum.notas[i]);
        printf("\nPromedio: %0.2f:", calcula_promedio_alumno(&alum));
        printf("\n\n");
        tam -= 1;
      fseek(archIdx, tam*sizeof(t_indice), SEEK_SET);
      fread(&idx, sizeof(t_indice), 1, archIdx);
    }

    fclose(archAlum);
    fclose(archIdx);

    return TODO_OK;
}
