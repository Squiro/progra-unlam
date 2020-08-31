#include "funciones.h"

int generarArchivoAlum(char * ruta)
{
    int i;
    t_alumno alums[4] = { { 1, "AA", 'M', 'A'}, { 3, "CC", 'F', 'A' }, { 4, "EE", 'M', 'A'}, { 5, "BB", 'F', 'A' } };
    FILE * arch;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ABRIR;

    for (i = 0; i < 4; i++)
        fwrite(&alums[i], sizeof(t_alumno), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int mostrarArchivoAlum(char * ruta)
{
    FILE * arch;
    t_alumno alum;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&alum, sizeof(t_alumno), 1, arch);

    printf("Mostrando archivo alumnos...\n\n");

    while (!feof(arch))
    {
        printf("\nDNI: %d", alum.dni);
        printf("\nAPYN: %s", alum.apyn);
        printf("\nSexo: %c", alum.sex);
        printf("\nEstado: %c", alum.estado);
        printf("\n\n");
        fread(&alum, sizeof(t_alumno), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int generarIndice(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    t_alumno alum;
    t_indice idx;
    int count = 0;

    FILE * archAlum, * archIdx;

    archAlum = fopen(rutaAlum, "rb");

    if (!archAlum)
        return ERROR_ABRIR;

    fread(&alum, sizeof(t_alumno), 1, archAlum);

    while (!feof(archAlum))
    {
        idx.dni = alum.dni;
        idx.numReg = count;
        insertar(pa, &idx, compararDNI);
        count++;
        fread(&alum, sizeof(t_alumno), 1, archAlum);
    }

    archIdx = fopen(rutaIdx, "wb");

    if (!archIdx)
        return ERROR_ABRIR;

    generarArchivoIndice(pa, archIdx);

    fclose(archAlum);
    fclose(archIdx);

    return SUCCESS;
}

void generarArchivoIndice(t_arbol * pa, FILE * arch)
{
    if (*pa)
    {
        generarArchivoIndice(&(*pa)->izq, arch);
        fwrite(&(*pa)->dato, sizeof(t_dato), 1, arch);
        generarArchivoIndice(&(*pa)->der, arch);
    }
}

int mostrarIndice(char * rutaIdx)
{
    t_indice idx;
    FILE * arch;

    arch = fopen(rutaIdx, "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&idx, sizeof(t_indice), 1, arch);

    printf("\n\n Mostrando el archivo indice...");

    while (!feof(arch))
    {
        printf("\nDNI: %d", idx.dni);
        printf("\nnumReg: %d", idx.numReg);
        printf("\n\n");
        fread(&idx, sizeof(t_indice), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int alta(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    t_alumno alum;
    t_indice idx;

    FILE * archAlum, * archIdx;

    ingresarAlumno(&alum);

    archAlum = fopen(rutaAlum, "ab");

    if (!archAlum)
        return ERROR_ABRIR;

    archIdx = fopen(rutaIdx, "wb");

    if (!archIdx)
    {
        fclose(archAlum);
        return ERROR_ABRIR;
    }

    fwrite(&alum, sizeof(t_alumno), 1, archAlum);

    idx.dni = alum.dni;
    idx.numReg = ftell(archAlum)/sizeof(t_alumno)-1;

    insertar(pa, &idx, compararDNI);

    generarArchivoIndice(pa, archIdx);

    fclose(archAlum);
    fclose(archIdx);

    return SUCCESS;
}

void ingresarAlumno(t_alumno * alum)
{
    fflush(stdin);
    printf("Ingrese el DNI: ");
    scanf("%d", &alum->dni);
    printf("\nIngrese el nombre: ");
    scanf("%s", alum->apyn);
    printf("\nIngrese el sexo: ");
    scanf("%c", &alum->sex);
    alum->estado = 'A';
}

int baja(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    t_indice idx;
    FILE * archIdx;

    printf("Ingrese el DNI a dar de baja: ");
    scanf("%d", &idx.dni);

    buscarClave(pa, &idx, compararDNI);

    if (idx.dni != -1)
    {
        modificarAlumno(rutaAlum, idx.numReg);
        eliminarDeArbol(pa, &idx, compararDNI);

        archIdx = fopen(rutaIdx, "wb");

        if (!archIdx)
            return ERROR_ABRIR;

        generarArchivoIndice(pa, archIdx);
        fclose(archIdx);
    }
    else
        printf("No se encontro al alumno.\n");

    return SUCCESS;
}

int modificarAlumno(char * rutaAlum, int offset)
{
    t_alumno alum;
    FILE * arch;

    arch = fopen(rutaAlum, "rb+");

    if (!arch)
        return ERROR_ABRIR;

    fseek(arch, offset*sizeof(t_alumno), SEEK_SET);

    fread(&alum, sizeof(t_alumno), 1, arch);
    alum.estado = 'B';
    fseek(arch, -1*sizeof(t_alumno), SEEK_CUR);
    fseek(arch, 0, SEEK_CUR);
    fwrite(&alum, sizeof(t_alumno), 1, arch);

    fclose(arch);

    return SUCCESS;

}
