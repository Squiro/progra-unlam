#include "funciones.h"

void mostrarVector(int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", vec[i]);

    printf("\n\n");
}

int menorAMayor(const void *arg1, const void *arg2)
{
    int *num1 = (int *)arg1, *num2 = (int *)arg2;
    return *num1 - *num2;
}

int mayorAMenor(const void *arg1, const void *arg2)
{
    int * num1 = (int *)arg1, * num2 = (int *)arg2;
    return *num2 - *num1;
}

int compararAND(const void *arg1, const void*arg2)
{
    t_empleado *emp1 = (t_empleado *)arg1, *emp2 = (t_empleado *)arg2;
    int cmp;

    if (!(cmp = strcmp(emp1->apellido, emp2->apellido)))
        if (!(cmp = strcmp(emp1->nombre, emp2->nombre)))
            return emp1->dni - emp2->dni;

    return cmp;
}

void mostrarEmpleados(t_empleado * emp, int size)
{
    int i;

    for (i = 0; i < size; i++, emp++)
    {
        printf("\n\nAp: %s", emp->apellido);
        printf("\nNom: %s", emp->nombre);
        printf("\nDni: %d", emp->dni);
    }
}

int compararDNA(const void *arg1, const void*arg2)
{
    t_empleado *emp1 = (t_empleado *)arg1, *emp2 = (t_empleado *)arg2;
    int cmp;

    if(!(cmp=emp1->dni - emp2->dni))
        if (!(cmp = strcmp(emp1->nombre, emp2->nombre)))
            return strcmp(emp1->apellido, emp2->apellido);
    return cmp;
}

int compararDNAmayAMen(const void *arg1, const void*arg2)
{
    t_empleado *emp1 = (t_empleado *)arg1, *emp2 = (t_empleado *)arg2;
    int cmp;

    if(!(cmp=emp2->dni - emp1->dni))
        if (!(cmp = strcmp(emp2->nombre, emp1->nombre)))
            return strcmp(emp2->apellido, emp1->apellido);
    return cmp;
}
