#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>


void listar_ape_asc(const t_lista * pl)
{
    /*t_lista lista;
    crearLista(&lista);
    //Reccoremos e insertamos en la lista
    recorrer_arbol_pre(pa, enlistarAsc, &lista);*/
    //mostrarLista(&lista);
    //vaciarLista(&lista);
    recorrerAscdente(pl);
}

void listar_ape_desc(const t_lista * pl)
{
    /*t_lista lista;
    crearLista(&lista);
    //Reccoremos e insertamos en la lista
    recorrer_arbol_pre(pa, enlistarDesc, &lista);
    //mostrarLista(&lista);
    //vaciarLista(&lista);*/
    recorrerDescendente(pl);
}

// /!\ Buscar mayor promedio en arbol

// /!\ Crear un struct que tenga al alumno y al promedio

void mayor_promedio(const t_arbol *pa)
{
    t_alumno mayor = {0, "", {1}, 1};
    mayor_prom_arbol(pa, &mayor);
    printf("El alumno con mayor promedio es: %s\nPromedio de: %lf\n",mayor.apyn, calcula_promedio_alumno(&mayor));
}

float calcula_promedio_alumno(const t_alumno * alu)
{
    int i = 0, prom = 0;

    for (i = 0; i < alu->cant_materias; i++)
    {
        prom += alu->notas[i];
    }

    prom /= alu->cant_materias;

    return prom;
}
