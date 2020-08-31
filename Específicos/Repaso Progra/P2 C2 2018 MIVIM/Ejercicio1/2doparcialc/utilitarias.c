#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>
#include "lista_doble.h"

void listar_alumnos_asc(const t_lista * pl)
{
    recorrerAscendente(pl);
}

void listar_alumnos_desc(const t_lista * pl)
{
    recorrerDescendente(pl);
}

void mayor_promedio(const t_arbol *pa)
{
    t_promedio prom;
    prom.promedio = 0;

    buscarMayorPromedio(pa, &prom);
//    printf("Nombre: %s\n", prom.alum.apyn);
    mostrar(&prom.alum);
    printf("Promedio: %0.3f\n", prom.promedio);
}

float calcula_promedio_alumno(const t_alumno* alu)
{
    int i, prom = 0;

    for (i = 0; i < alu->cant_materias; i++)
        prom += alu->notas[i];

    prom /= alu->cant_materias;

    return prom;
}
