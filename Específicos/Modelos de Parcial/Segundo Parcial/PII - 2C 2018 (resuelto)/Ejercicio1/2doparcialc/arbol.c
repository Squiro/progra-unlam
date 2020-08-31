#include <Tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arbol.h>
#include <math.h>
#include "lista_doble.h"
#include<utilitarias.h>

void crear_arbol(t_arbol* pa)
{
    *pa = NULL;
}

int insertar_en_arbol_bin_busq(t_arbol* pa, const t_info* pd, t_cmp comparar)
{
    int comp;

    if (*pa)
    {
        comp = comparar(&(*pa)->info, pd);

        if (comp < 0)
            return insertar_en_arbol_bin_busq(&(*pa)->pder, pd, comparar);
        else if (comp > 0)
            return insertar_en_arbol_bin_busq(&(*pa)->pizq, pd, comparar);
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

/*void enlistarDesc(t_info * pinfo, void * datos_accion)
{
    insertarOrdenado(datos_accion, pinfo, compararNombresDesc);
}

void enlistarProm(t_info * pinfo, void * datos_accion)
{
    insertarOrdenado(datos_accion, pinfo, compararPromedio);
}*/


int cargar_arbol_de_archivo_preorden(t_arbol* pa, const char* path)
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

int compararDNI(const t_info *info1, const t_info * info2)
{
    return info1->dni - info2->dni;
}

void mayor_prom_arbol(const t_arbol * pa,t_info * alumno)
{
    if(!(*pa))
        return;

    if((calcula_promedio_alumno(&(*pa)->info)) > (calcula_promedio_alumno(alumno)))
        *alumno=(*pa)->info;

    mayor_prom_arbol(&(*pa)->pizq, alumno);
    mayor_prom_arbol(&(*pa)->pder, alumno);
}
