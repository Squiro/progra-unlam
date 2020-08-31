#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>

/*void listar_ape_desc(const t_arbol * pa)
{
    recorrer_arbol_enorden_inverso(pa, mostrar, NULL);
}*/

//Asumo que por promedio general me pide la suma de los promedios de los alumnos dividido la cantidad de alumnos
void promedio_general(const t_arbol * pa)
{
    t_promedio prom;
    prom.prom = 0;
    prom.cantAlu = 0;
    calcula_promedio_general(pa, &prom);
    printf("El promedio general es: %0.3f", prom.prom/prom.cantAlu);

}

void calcula_promedio_general(const t_arbol * pa, t_promedio * prom)
{
    if (*pa)
    {
        prom->prom += calcula_promedio_alumno(&(*pa)->info);
        prom->cantAlu += 1;
        calcula_promedio_general(&(*pa)->pizq, prom);
        calcula_promedio_general(&(*pa)->pder, prom);
    }
}

float calcula_promedio_alumno(const t_alumno* alu)
{
    float prom = 0;
    int i;

    for (i = 0; i < alu->cant_materias; i++)
        prom += alu->notas[i];

    prom /= alu->cant_materias;

    return prom;
}
