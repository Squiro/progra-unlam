#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int insertar(t_arbol *pa, const t_dato *d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            insertar(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            insertar(&(*pa)->izq, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        *pa = (t_nodo *) malloc(sizeof(t_nodo));

        if (!*pa)
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }

    return SUCCESS;
}

void recorrerEnOrden(t_arbol *pa, t_accion accion)
{
    if (*pa)
    {
        recorrerEnOrden(&(*pa)->izq, accion);
        accion(&(*pa)->dato);
        recorrerEnOrden(&(*pa)->der, accion);
    }
}

void leerEnOrden(t_arbol *pa, FILE * arch, int ini, int fin, t_cmp comparar)
{
    t_dato dato;
    int mid = (ini+fin)/2;

    if (ini > fin)
        return;

    fseek(arch, mid*sizeof(t_dato), SEEK_SET);
    fread(&dato, sizeof(t_dato), 1, arch);
    insertar(pa, &dato, comparar);
    leerEnOrden(&(*pa)->izq, arch, ini, mid-1, comparar);
    leerEnOrden(&(*pa)->der, arch, mid+1, fin, comparar);
}

void mostrar(const void *arg)
{
    t_empleado * emp = (t_empleado *) arg;

    printf("\nDNI: %d", emp->dni);
    printf("\nNombre: %s", emp->apyn);
    printf("\nSueldo: %0.2lf", emp->sueldo);
    printf("\n\n");
}

int compararDNI(const void *arg1, const void *arg2)
{
    t_empleado * emp1 = (t_empleado *) arg1, * emp2 = (t_empleado *) arg2;

    return emp1->dni - emp2->dni;
}
