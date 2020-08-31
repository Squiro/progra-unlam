#include "funciones.h"

int generarLote()
{
    t_empleado emps[] = { { 111, "Jose", "Polverini", 500.00 }, { 222, "Juan", "Perez", 120.30 }, { 333, "Dario", "Oirad", 400.25 }, { 444, "Josefina", "Polverina", 220.30 } };
    FILE * arch;

    arch = fopen("empleados.bin", "wb");

    if (!arch)
    {
        printf("No se pudo abrir el archivo.");
        return ERROR_ABRIR;
    }

    fwrite(emps, sizeof(emps), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int guardarEnPila(t_pila *p)
{
    t_empleado emp;
    FILE * arch;

    arch = fopen("empleados.bin", "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&emp, sizeof(emp), 1, arch);

    while (!feof(arch))
    {
        apilar(p, &emp);
        fread(&emp, sizeof(emp), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int ordenarPila(t_pila *p, t_cmp comparar)
{
    //Declaro dos variables del tipo empleado
    t_empleado emp, aux;
    //Declaro una pila auxiliar
    t_pila pilaAux;
    //Inicializo la pila
    crearPila(&pilaAux, sizeof(t_empleado));

    //Iteramos mientras que la primera pila no esté vacía
    while (!pilaVacia(p))
    {
        desapilar(p, &emp);
        verTope(&pilaAux, &aux);

        while (!pilaVacia(&pilaAux) && comparar(&emp, &aux) > 0)
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

int generarArchivo(t_pila *p)
{
    t_empleado emp;
    FILE *arch;

    arch = fopen("resultado.bin", "wb");

    if (!arch)
        return ERROR_ABRIR;

    while (!pilaVacia(p))
    {
        desapilar(p, &emp);
        fwrite(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int mostrarArchivo()
{
    t_empleado emp;
    FILE *arch;

    arch = fopen("resultado.bin", "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&emp, sizeof(t_empleado), 1, arch);

    while (!feof(arch))
    {
        printf("\n\nDNI: %d", emp.dni);
        printf("\nNombre: %s", emp.nombre);
        printf("\nApellido: %s", emp.apellido);
        printf("\nSueldo: %0.3f", emp.sueldo);
        fread(&emp, sizeof(t_empleado), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

int compararEmpleados(const void * arg1, const void * arg2)
{
    t_empleado * emp1 = (t_empleado *) arg1, * emp2 = (t_empleado *) arg2;
    return (int) emp1->sueldo - emp2->sueldo;
}
