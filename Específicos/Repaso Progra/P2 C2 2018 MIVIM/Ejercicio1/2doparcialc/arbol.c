#include <Tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arbol.h>
#include <math.h>
#include "lista_doble.h"
#include <utilitarias.h>

int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, int (*cmp)(const t_info*, const t_info*))
{
    int comp;

    if (*pa)
    {
        comp = cmp(&(*pa)->info, pd);

        if (comp < 0)
            insertar_en_arbol_bin_busq(&(*pa)->pder, pd, cmp);
        else if (comp > 0)
            insertar_en_arbol_bin_busq(&(*pa)->pizq, pd, cmp);
        else
            return DUPLICADO;
    }
    else
    {

        *pa = (t_nodo_arbol *) malloc(sizeof(t_nodo_arbol));

        (*pa)->info = *pd;
        (*pa)->pder = NULL;
        (*pa)->pizq = NULL;
    }

    return TODO_OK;
}

//R I D
void recorrer_arbol_pre(const t_arbol* pa, void (*accion)(t_info* pinfo, void* datos_accion), void* datos_accion)
{
    if (*pa)
    {

        accion(&(*pa)->info, datos_accion);
        recorrer_arbol_pre(&(*pa)->pizq, accion, datos_accion);
        recorrer_arbol_pre(&(*pa)->pder, accion, datos_accion);
    }
}

void enlistar(t_info * pinfo, void * datos_accion)
{
    insertarOrdenado(datos_accion, pinfo, compararNombresAsc);
}

void buscarMayorPromedio(const t_arbol * pa, t_promedio * prom)
{
    if (!(*pa))
        return;

    float promedio = 0;

    promedio = calcula_promedio_alumno(&(*pa)->info);

    if (promedio > prom->promedio)
    {
        prom->promedio = promedio;
        prom->alum = (*pa)->info;
    }
    buscarMayorPromedio(&(*pa)->pizq, prom);
    buscarMayorPromedio(&(*pa)->pder, prom);
}

int cargar_arbol_de_archivo_preorden(t_arbol * pa, const char * path)
{
    FILE * arch;
    t_info info;
    arch = fopen(path, "rb");

    if (!arch)
        return ERROR_ARCHIVO;

    fread(&info, sizeof(t_info), 1, arch);

    while (!feof(arch))
    {
        insertar_en_arbol_bin_busq(pa, &info, compararDNI);
        fread(&info, sizeof(t_info), 1, arch);
    }

    fclose(arch);
    return TODO_OK;
}

int grabar_arbol_en_archivo_preorden(t_arbol* pa, const char* path)
{
    FILE * arch;

    arch = fopen(path, "wb");

    if (!arch)
        return ERROR_ARCHIVO;

    guardar_arbol_preorden(pa, arch);

    return TODO_OK;
}

void guardar_arbol_preorden(t_arbol * pa, FILE * arch)
{
    if (!(*pa))
        return;
    fwrite(&(*pa)->info, sizeof(t_info), 1, arch);
    guardar_arbol_preorden(&(*pa)->pizq, arch);
    guardar_arbol_preorden(&(*pa)->pder, arch);

}

int compararDNI(const t_info * arg1, const t_info * arg2)
{
    t_info * info1 = (t_info *) arg1, * info2 = (t_info *) arg2;

    return info1->dni-info2->dni;
}
