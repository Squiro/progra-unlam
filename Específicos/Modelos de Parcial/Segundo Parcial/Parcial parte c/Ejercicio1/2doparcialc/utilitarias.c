#include<utilitarias.h>
#include<string.h>
#include<varias.h>
#include<ctype.h>
#include "stdlib.h"

int comparar_ap(const void *d1,const void *d2)
{
    char * dat1=((t_info*)d1)->apyn;
    char * dat2=((t_info*)d2)->apyn;
    return strcmp(dat1,dat2);
}
void crear_lista(t_lista * pl)
{
    *pl=NULL;
}
int insertar_en_lista_ordenada(t_lista * pl,const t_info * d,t_comp comp)
{
    t_nodo_l * nue;
    if(!(*pl))
    {
        nue=(t_nodo_l*)malloc(sizeof(t_nodo_l));
        if(!nue)
            return SIN_MEM;
        nue->info=*d;
        nue->sig=NULL;
        *pl=nue;
        return TODO_OK;
    }
    while(*pl && comp(d,&(*pl)->info)<0)
        pl=&(*pl)->sig;
    nue=(t_nodo_l*)malloc(sizeof(t_nodo_l));
    if(!nue)
        return SIN_MEM;
    nue->info=*d;
    nue->sig=*pl;
    *pl=nue;
    return TODO_OK;
}
void imprimir_alumno(const t_alumno * alu)
{
    int i=0;
    printf("%-15s%-10d %-5d",alu->apyn,alu->dni,alu->cant_materias);
    while(i!=alu->cant_materias)
        printf("%d|",alu->notas[i++]);
    puts("\n");
}
void vaciar_lista(t_lista *pl)
{
    if(!(*pl))
        return;

    t_nodo_l * nae;
    while((*pl)->sig)
    {
        nae=*pl;
        *pl=(*pl)->sig;
        free(nae);
    }
    free(*pl);
    (*pl)=NULL;
}
void mostrar_lista_asc(const t_lista * pl)
{
    if(!(*pl))
        return;
    mostrar_lista_asc(&(*pl)->sig);
    imprimir_alumno(&(*pl)->info);
}
void mostrar_lista_desc(const t_lista *pl)
{
    if(!(*pl))
        return;
    imprimir_alumno(&(*pl)->info);
    mostrar_lista_desc(&(*pl)->sig);
}
void cargar_lista_de_arbol(const t_arbol * pa,t_lista * pl)
{
  recorrer_arbol_inorden_insertar_en_lista(pa,pl);
}
int listar_por_apellido(t_tipo mostrar)
{
    FILE * pf = fopen("..\\archivos\\alumnos.dat","rb");
    t_alumno alumno;
    t_lista lista;
    crear_lista(&lista);
    if(!pf)
        return NO_ABIERTO;
    fread(&alumno,sizeof(t_alumno),1,pf);
    while(!feof(pf))
    {
        insertar_en_lista_ordenada(&lista,&alumno,comparar_ap);
        fread(&alumno,sizeof(t_alumno),1,pf);
    }
    mostrar(&lista);
    fclose(pf);
    vaciar_lista(&lista);
    return TODO_OK;
}
void mejor_promedio(t_alumno * dato)
{
    FILE * pf=fopen("..\\archivos\\alumnos.dat","rb");
    if(!pf)
        return;
    t_alumno alumnos;
    int promedio=0;
    int i=0;
    int promedio_act=0;
    t_alumno mejor;
    fread(&alumnos,sizeof(t_alumno),1,pf);

    mejor=alumnos;

    while(i<alumnos.cant_materias)
    {
        promedio+=alumnos.notas[i++];
    }
    promedio=promedio/alumnos.cant_materias;
    promedio_act=promedio;

    while(!feof(pf))
    {
        i=0;
        while(i<alumnos.cant_materias)
        {
            promedio+=alumnos.notas[i++];
        }
        promedio=promedio/alumnos.cant_materias;
        if(promedio>promedio_act)
        {
            promedio_act=promedio;
            mejor=alumnos;
        }
        fread(&alumnos,sizeof(t_alumno),1,pf);
    }
    imprimir_alumno(&mejor);
    *dato=mejor;
    fclose(pf);
    return;
}
void recorrer_arbol_inorden_insertar_en_lista(const t_arbol * pa,t_lista * pl)
{
    if(!(*pa))
        return;
    recorrer_arbol_inorden_insertar_en_lista(&(*pa)->pizq,pl);
    insertar_en_lista_ordenada(pl,&(*pa)->info,comparar_ap);
    recorrer_arbol_inorden_insertar_en_lista(&(*pa)->pder,pl);

}
void listar_por_apellido_indice(const t_arbol * pa,t_tipo mostrar)
{
    t_lista lista;
    crear_lista(&lista);
    recorrer_arbol_inorden_insertar_en_lista(pa,&lista);
    mostrar(&lista);
    vaciar_lista(&lista);
}

