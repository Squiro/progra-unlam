#include "funciones.h"

int generarLote(char * ruta)
{
    int i;
    FILE * arch;
    t_empleado emps[3] = { { 1, "Jose", 250 }, { 4, "Martin", 225 }, { 2, "Martina", 230 } };

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    for (i = 0; i < 3; i++)
        fwrite(&emps[i], sizeof(t_empleado), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int guardarEnPila(t_pila *p, char * ruta)
{
    t_empleado emp;
    FILE * arch;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

    fread(&emp, sizeof(t_empleado), 1, arch);

    while (!feof(arch))
    {
        apilar(p, &emp);
        fread(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int ordenarPila(t_pila *p, t_cmp comparar)
{
    t_empleado emp, aux;
    t_pila pilaAux;

    crearPila(&pilaAux);

    while (!pilaVacia(p))
    {
        desapilar(p, &emp);
        verTope(&pilaAux, &aux);

        while (!pilaVacia(&pilaAux) && comparar(&emp, &aux) < 0)
        {
            desapilar(&pilaAux, &aux);
            apilar(p, &aux);
            verTope(&pilaAux, &aux);
        }
        apilar(&pilaAux, &emp);
    }

    while (!pilaVacia(&pilaAux))
    {
        desapilar(&pilaAux, &aux);
        apilar(p, &aux);
    }

    return SUCCESS;
}

int generarResultado(t_pila *p, char * ruta)
{
    t_empleado emp;
    FILE * arch;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    while (!pilaVacia(p))
    {
        desapilar(p, &emp);
        fwrite(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int mostrarArchivo(char * ruta)
{
    t_empleado emp;
    FILE * arch;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

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

int compararDNI(const void *arg1, const void *arg2)
{
    t_empleado * emp1 = (t_empleado *) arg1, * emp2 = (t_empleado *) arg2;

    return emp1->dni-emp2->dni;
}
