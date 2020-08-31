#include <Tipos.h>
#include <stdio.h>
#include <stdlib.h>
#include <Arbol.h>
#include <math.h>
#include "utilitarias.h"
void grabar_arbol_pre(const t_arbol * pa,FILE * pf)
{
    if(!(*pa))
        return ;
    fwrite(&(*pa)->info,sizeof(t_alumno),1,pf);
    grabar_arbol_pre(&(*pa)->pizq,pf);
    grabar_arbol_pre(&(*pa)->pizq,pf);
}
int grabar_arbol_en_archivo_pre(t_arbol* pa, const char* path)
{
    FILE * pf=fopen("wb",path);
    if(!pf)
        return ERROR_ARCHIVO;
    grabar_arbol_pre(pa,pf);
    fclose(pf);
    return TODO_OK;
}
int insertar_en_arbol_bin(t_arbol* pa, const t_info* pd, t_comp comp) ///Retorna TODO_OK, DUPLICADO O SIN_MEM
{
    if(!(*pa))
    {
        *pa=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
        if(!(*pa))
            return SIN_MEM;
        (*pa)->info=*pd;
        (*pa)->pder=(*pa)->pizq=NULL;
    }
    if(comp(pd,&(*pa)->info)==0)
        return DUPLICADO;
    if(comp(pd,&(*pa)->info)>0)
        insertar_en_arbol_bin(&(*pa)->pder,pd,comp);
    else insertar_en_arbol_bin(&(*pa)->pizq,pd,comp);
    return TODO_OK;
}
int cargar_arbol_de_archivo_pre(t_arbol* pa, const char* path) ///Retorna TODO_OK, ERROR_ARCHIVO o SIN_MEM
{
    FILE * pf=fopen(path,"rb");
    if(!pf)
        return ERROR_ARCHIVO;
    t_alumno dato;
    fread(&dato,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        if(insertar_en_arbol_bin(pa,&dato,comparar_ap)==SIN_MEM)
          return SIN_MEM;
        fread(&dato,sizeof(t_alumno),1,pf);
    }
    return TODO_OK;
}
int prom(const t_info alu)
{
    int i=0;
    int result=0;
    for(i=0; i<alu.cant_materias; i++)
        result+=alu.notas[i];
    result=result/alu.cant_materias;
    return result;
}
void mayor_prom_arbol(const t_arbol * pa,t_info * alumno)
{
    if(!(*pa))
        return;
    if((prom((*pa)->info))>(prom(*alumno)))
        *alumno=(*pa)->info;
    mayor_prom_arbol(&(*pa)->pizq,alumno);
    mayor_prom_arbol(&(*pa)->pder,alumno);
}
void mayor_promedio_arbol_mio(const t_arbol * pa)
{
    t_alumno mayor= {0,"",{1},1};
    mayor_prom_arbol(pa,&mayor);
    printf("El alumno con mayor promedio es: %s\nPromedio de: %d\n",mayor.apyn,prom(mayor));
}
