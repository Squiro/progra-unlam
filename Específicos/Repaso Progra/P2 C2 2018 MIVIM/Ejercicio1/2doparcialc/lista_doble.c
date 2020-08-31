#include "lista_doble.h"
#include <varias.h>

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertarOrdenado(t_lista * pl, const t_info * d, t_comp comparar)
{
    t_nodo_lista * actual = *pl, * sigAux, * antAux, * nuevo;
    int cmp;

    if (actual)
    {
        while (actual->sig && (cmp = comparar(&actual->info, d)) < 0)
            actual = actual->sig;

        while (actual->ant && (cmp = comparar(&actual->info, d)) > 0)
            actual = actual->ant;

        cmp = comparar(&actual->info, d);

        if (cmp < 0)
        {
            sigAux = actual->sig;
            antAux = actual;
        }
        else if (cmp > 0)
        {
            antAux = actual->ant;
            sigAux = actual;
        }
        else
            return DUPLICADO;
    }
    else
    {
        sigAux = NULL;
        antAux = NULL;
    }

    nuevo = (t_nodo_lista *) malloc(sizeof(t_nodo_lista));

    if (!nuevo)
        return SIN_MEM;

    nuevo->info = *d;
    nuevo->sig = sigAux;
    nuevo->ant = antAux;

    if (antAux)
        antAux->sig = nuevo;
    if (sigAux)
        sigAux->ant = nuevo;

    *pl = nuevo;

    return TODO_OK;
}

void recorrerAscendente(const t_lista * pl)
{
    t_nodo_lista * actual = *pl;

    if (!actual)
        return;

    while (actual->ant)
        actual = actual->ant;

    while (actual->sig)
    {
        mostrar(&actual->info);
        actual = actual->sig;
    }
}

void recorrerDescendente(const t_lista * pl)
{
    t_nodo_lista * actual = *pl;

    if (!actual)
        return;

    while (actual->sig)
        actual = actual->sig;

    while (actual->ant)
    {
        mostrar(&actual->info);
        actual = actual->ant;
    }
}

void mostrar(t_info * alum)
{
    int i;
    printf("DNI: %d\n", alum->dni);
    printf("Apellido y Nombre: %s\n", alum->apyn);
    printf("Notas: ");
    for (i = 0; i < alum->cant_materias; i++)
        printf("-%d ", alum->notas[i]);
    printf("\n\n");
}

int compararNombresAsc(const void * arg1, const void * arg2)
{
    t_info * dato1 = (t_info *) arg1, * dato2 = (t_info *) arg2;

    return strcmp(dato1->apyn, dato2->apyn);
}
