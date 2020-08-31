#include "lista_doble.h"
#include <string.h>
#include <utilitarias.h>

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertarOrdenado(t_lista * pl, const t_info * d, t_comp comparar)
{
    t_nodo_lista * actual = *pl, * antAux, * sigAux, * nuevo;
    int cmp;

    //Si existe un nodo...
    if (actual)
    {
        while (actual->sig && (cmp = comparar(&actual->info, d)) < 0)
            actual = actual->sig;

        while (actual->ant && (cmp = comparar(&actual->info, d)) > 0)
            actual = actual->ant;

        //Es imprescindible hacer este...
        cmp = comparar(&actual->info, d);

        if (cmp < 0)
        {
            antAux = actual;
            sigAux = actual->sig;
        }
        else if (cmp > 0)
        {
            sigAux = actual;
            antAux = actual->ant;
        }
        else
            return DUPLICADO;
    }
    else
    {
        antAux = NULL;
        sigAux = NULL;
    }

    nuevo = (t_nodo_lista *) malloc(sizeof(t_nodo_lista));

    if (!nuevo)
        return SIN_MEM;

    nuevo->info = *d;
    nuevo->ant = antAux;
    nuevo->sig = sigAux;

    if (antAux)
        antAux->sig = nuevo;
    if (sigAux)
        sigAux->ant = nuevo;

    *pl = nuevo;

    return TODO_OK;
}

void recorrerAscdente(const t_lista * pl)
{
    t_nodo_lista * actual = *pl;

    if (!actual)
        return;

    while (actual->ant)
        actual = actual->ant;

    while(actual->sig)
    {
        mostrar(actual);
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

    while(actual->ant)
    {
        mostrar(actual);
        actual = actual->ant;
    }
}

void mostrar(t_nodo_lista * alum)
{
    int i;
    printf("DNI: %d\n", alum->info.dni);
    printf("Apellido y Nombre: %s\n", alum->info.apyn);
    printf("Notas: ");
    for (i = 0; i < alum->info.cant_materias; i++)
        printf("-%d ", alum->info.notas[i]);
    printf("\n\n");
}

int compararNombresAsc(const void *arg1, const void *arg2)
{
    t_info * info1 = (t_info *) arg1, * info2 = (t_info *) arg2;

    return strcmp(info1->apyn, info2->apyn);
}
