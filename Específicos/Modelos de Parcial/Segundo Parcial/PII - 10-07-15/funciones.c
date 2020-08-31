#include "funciones.h"

int generarArchivoAlum(char * ruta)
{
    FILE * arch;
    t_alumno alum[4] = { { 40808298, "Alesio", "Sinopoli", 'A' }, { 37444222, "Harry", "Potter", 'A'}, { 20101244, "Ana", "Lopez", 'A' },
    { 44293123, "Alguien", "Random", 'A' } };
    int i;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ABRIR;

    for (i = 0; i < 4; i++)
    {
        fwrite(&alum[i], sizeof(t_alumno), 1, arch);
    }

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
    printf("Mostrando el archivo %s: \n\n", ruta);

    while (!feof(arch))
    {
        printf("DNI: %d\n", alum.dni);
        printf("Nombre: %s\n", alum.nombre);
        printf("Apellido: %s\n", alum.apellido);
        printf("Estado: %c\n\n", alum.estado);
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
        insertarOrdenado(pa, &idx, compararDNI);
        count++;
        fread(&alum, sizeof(t_alumno), 1, archAlum);
    }

    archIdx = fopen(rutaIdx, "wb");

    generarArchivoIndice(pa, archIdx);

    fclose(archAlum);
    fclose(archIdx);

    return SUCCESS;
}

void generarArchivoIndice(t_arbol * pa, FILE * archIdx)
{
    if (*pa)
    {
        generarArchivoIndice(&(*pa)->izq, archIdx);
        fwrite(&(*pa)->dato, sizeof(t_indice), 1, archIdx);
        generarArchivoIndice(&(*pa)->der, archIdx);
    }

}

/** Sobreescribe el archivo indice para empezar el guardado

int generarArchivoIndice(t_arbol * pa, FILE * rutaIdx)
{
    FILE * arch;

    arch = fopen(rutaIdx, "wb");

    if (!arch)
        return ERROR_ABRIR;

    fclose(arch);

    inOrden(pa, guardarEnIndice);

    return SUCCESS;

}*/

/*int guardarEnIndice(const void * arg, const void * arg2)
{
    FILE * arch;
    t_indice * idx = (t_indice *) arg;

    arch = fopen("alumnos.idx", "ab");

    if (!arch)
        return ERROR_ABRIR;

    fwrite(idx, sizeof(t_indice), 1, arch);

    fclose(arch);

    return SUCCESS;
}*/

int mostrarIndice(char * ruta)
{
    FILE * arch;
    t_indice idx;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&idx, sizeof(t_indice), 1, arch);

    printf("Mostrando el archivo %s: \n\n", ruta);

    while (!feof(arch))
    {
        printf("DNI: %d\n", idx.dni);
        printf("NumReg: %d\n", idx.numReg);
        fread(&idx, sizeof(t_indice), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

/** Funciones alta y baja */

int alta(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    t_alumno alum;
    t_indice idx;

    ingresarAlumno(&alum);

    FILE * archAlum, * archIdx;

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
    idx.numReg = ftell(archAlum)/sizeof(t_alumno)-1; //Menos 1?

    insertarOrdenado(pa, &idx, compararDNI);

    generarArchivoIndice(pa, archIdx);

    fclose(archAlum);
    fclose(archIdx);

    return SUCCESS;
}

void ingresarAlumno(t_alumno * alum)
{
    fflush(stdin);
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", alum->nombre);
    printf("\nIngrese el apellido del alumno: ");
    scanf("%s", alum->apellido);
    printf("\nIngrese el DNI del alumno: ");
    scanf("%d", &alum->dni);
    alum->estado = 'A';
}

int baja(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    t_indice idx;
    FILE * archIdx;
    printf("Ingrese el DNI a dar de baja: ");
    scanf("%d", &idx.dni);

    //"Extraemos" los datos del indice (necesitamos saber el desplazamiento, solo conocemos la clave hasta ahora)
    buscarClave(pa, &idx, compararDNI, extraerNodo);

    //¿Realmente existe la clave ingresada? Si existe hacemos lo que tenemos que hacer
    if (idx.dni != -1)
    {
        //Modificamos al alumno en el archivo alumnos.dat
        modificarAlumno(rutaAlum, idx.numReg);
        //Borramos la entrada del indice
        eliminar_de_arbol(pa, &idx, compararDNI);
        //Sobreescribimos el archivo indice
        archIdx = fopen(rutaIdx, "wb");

        if (!archIdx)
            return ERROR_ABRIR;

        //Generamos el nuevo indice sin esa entrada
        generarArchivoIndice(pa, archIdx);
        //Una vez generado lo cerramos
        fclose(archIdx);
    }
    else
        printf("No se encontro al alumno. \n");


    return SUCCESS;
}

int modificarAlumno(char * rutaAlum, int offset)
{
    FILE * arch;
    t_alumno alum;

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
