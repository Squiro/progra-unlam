#include "lista.h"
#include <string.h>
#include <utilitarias.h>

/*void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertarOrdenado(t_lista * pl, const t_info * d, t_comp comparar)
{
    int cmp;

    while (*pl && (cmp = comparar(&(*pl)->info, d)) < 0)
        pl = &(*pl)->sig;


    t_nodo_lista * nuevo = (t_nodo_lista *) malloc(sizeof(t_nodo_lista));

    if (!nuevo)
        return SIN_MEM;

    nuevo->info = *d;

    nuevo->sig = *pl;

    *pl = nuevo;

    return TODO_OK;
}

void mostrarLista(t_lista * pl)
{
    int i;

    while (*pl)
    {
        printf("DNI: %d\n", (*pl)->info.dni);
        printf("Apellido y Nombre: %s\n", (*pl)->info.apyn);
        printf("Notas: ");
        for (i = 0; i < (*pl)->info.cant_materias; i++)
        printf("-%d ", (*pl)->info.notas[i]);
        printf("\n\n");
        pl = &(*pl)->sig;
    }
}

void vaciarLista(t_lista * pl)
{
    t_nodo_lista * aux;
    while (*pl)
    {
        aux = (*pl)->sig;
        free(*pl);
        pl = &aux;
    }

    *pl = NULL;
}

int verPrimero(t_lista * pl, t_info * d)
{
    if (!(*pl))
        return NO_EXISTE;

    *d = (*pl)->info;

    return TODO_OK;
}

int compararNombresAsc(const void *arg1, const void *arg2)
{
    t_info * info1 = (t_info *) arg1, * info2 = (t_info *) arg2;

    return strcmp(info1->apyn, info2->apyn);
}

int compararNombresDesc(const void *arg1, const void *arg2)
{
    t_info * info1 = (t_info *) arg1, * info2 = (t_info *) arg2;

    return strcmp(info2->apyn, info1->apyn);
}

int compararPromedio(const void *arg1, const void *arg2)
{
    t_info * info1 = (t_info *) arg1, * info2 = (t_info *) arg2;

    return calcula_promedio_alumno(info2) - calcula_promedio_alumno(info1);
}*/
