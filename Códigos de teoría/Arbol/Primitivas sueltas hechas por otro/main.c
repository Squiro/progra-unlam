#include "arbol.h"

/// crear, validar lleno y vacio.

void crear_arbol(t_arbol *pa)
{
    *pa=NULL;
}

int arbol_vacio(const t_arbol *pa)
{
    return *pa==NULL;
}

int arbol_lleno(const t_arbol *pa)
{
    t_nodoa *aux=(t_nodoa *)malloc(sizeof (t_nodoa));
    free(aux);
    return aux==NULL;
}

/// Insertar en orden (hecho en clase)

// Ciclica

/*int insertar_arbol_enorden(t_arbol *pa,const t_info *dato,int(*cmp)(const void *,const void *))
{
    int comp;
    while(*pa)
    {
        if((comp=cmp(dato,&(*pa)->info))>0)
            pa=&(*pa)->der;

        else if(comp<0)
            pa=&(*pa)->izq;
        else
            return DUPLICADO;
    }
    *pa=(t_nodoa *)malloc(sizeof(t_nodoa));
    if(*pa==NULL)
        return SIN_MEM;
    (*pa)->info=*dato;
    (*pa)->izq=(*pa)->der=NULL;
    return OK;
}*/

// Recursiva


int insertar_arbol_enorden(t_arbol *pa,const t_info *dato,int(*cmp)(const void *,const void *))
{
    int comp;
    if(*pa)
    {
        if((comp=cmp(dato,&(*pa)->info))>0)
            return insertar_arbol_enorden(&(*pa)->der,dato,cmp);
        if(comp<0)
            return insertar_arbol_enorden(&(*pa)->izq,dato,cmp);
        return DUPLICADO;
    }
    *pa=(t_nodoa *)malloc(sizeof(t_nodoa));
    if(*pa==NULL)
        return SIN_MEM;
    (*pa)->info=*dato;
    (*pa)->izq=(*pa)->der=NULL;
    return OK;
}

/// recorrer en orden (hecho en clase)

void recorrer_en_orden(const t_arbol *pa,void *param,void(*accion)(const t_info *,void *))
{
    if(!*pa)
        return;

    recorrer_en_orden(&(*pa)->izq,param,accion);    // IZQ
    accion(&(*pa)->info,param);                     // RAIZ
    recorrer_en_orden(&(*pa)->der,param,accion);    // DER

}


/// recorrer pos orden

void recorrer_enorden(const t_arbol *pa,void *param,void (*accion)(const t_info*,void*))
{
    if(!*pa)
        return;

    recorrer_preorden(&(*pa)->izq,param,accion);        // IZQ
    accion(&(*pa)->info,param);                         // RAIZ
    recorrer_preorden(&(*pa)->der,param,accion);        // DER
}


/// obtener  mayor y menor por nodo


t_arbol *obtener_mayor(const t_arbol *pa)
{
    if(!(*pa)->der)
        return (t_arbol *)pa;
    return obtener_mayor(&(*pa)->der);
}

t_arbol *obtener_menor(const t_arbol *pa)
{
    if(!(*pa)->izq)
        return (t_arbol *)pa;
    return obtener_menor(&(*pa)->izq);
}

/// Obtener mayor y menor elemento

t_info obtener_mayor_elemento(const t_arbol *arbol,void (*accion)(const t_info*,void*))
{
    t_info mayor=(*arbol)->info;
    recorrer_en_orden(arbol,&mayor,accion);
    return mayor;
}

t_info obtener_menor_elemento(const t_arbol *arbol,void (*accion)(const t_info*,void*))
{
    t_info menor=(*arbol)->info;
    recorrer_en_orden(arbol,&menor,accion);
    return menor;
}

/// contar nodos

int contar_nodos(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    return contar_nodos(&(*pa)->izq)+contar_nodos(&(*pa)->der)+1;
}

/// devolver altura

int altura_arbol(const t_arbol *pa)
{
    int ai;
    int ad;
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 1;
    ai = altura_arbol(&(*pa)->izq);
    ad = altura_arbol(&(*pa)->der);
    return (MAYOR(ad,ai))+1;
}

/// contar hasta nivel

int contar_hasta_nivel(const t_arbol *pa,int n)
{
    if(!*pa||n<0)
        return 0;
    if(ES_HOJA)
        return 1;
    return contar_hasta_nivel(&(*pa)->izq,n-1)+contar_hasta_nivel(&(*pa)->der,n-1)+1;
}

/// completo hasta nivel (h-1)

int completo_hasta_nivel(const t_arbol *pa,int n)
{
    if(n<0)
        return 1;
    if(!*pa)
        return 0;
    return completo_hasta_nivel(&(*pa)->izq,n-1)&&completo_hasta_nivel(&(*pa)->der,n-1);
}

/// arbol avl

int arbol_avl(const t_arbol *pa)
{
    int hi,hd;
    if(!*pa)
        return 1;
    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);
    if(abs(hi-hd)>1)
        return 0;
    return arbol_avl(&(*pa)->izq)&&arbol_avl(&(*pa)->izq);
}


/// eliminar arbol (hecho en clase)

int eliminar_arbol(t_arbol *pa,t_info *dato,int (*cmp)(const void *,const void *))
{
    pa=buscar_nodo(pa,dato,cmp);
    if(!pa)
        return 0;
    *dato=(*pa)->info;
    return eliminar_raiz(pa);
}

int eliminar_raiz(t_arbol *pa)
{
    t_arbol *reemp;
    int hi,hd;
    if(!*pa)
        return 0;
    if(ES_HOJA)
    {
        free(*pa);
        *pa=NULL;
        return 1;
    }
    hi = altura_arbol(&(*pa)->izq);
    hd = altura_arbol(&(*pa)->der);
    reemp = hi>hd?obtener_mayor(&(*pa)->izq):obtener_menor(&(*pa)->der);
    (*pa)->info=(*reemp)->info;
    return eliminar_raiz(reemp);
}

t_arbol *buscar_nodo(const t_arbol *pa,t_info *dato,int (*cmp)(const void*,const void*))
{
    // esta parte la hice yo

    int comp;
    if(!*pa)
        return NULL;
    if((comp=cmp(dato,&(*pa)->info))==0)
        return (t_arbol *)pa;
    if(comp<0)
        return buscar_nodo(&(*pa)->izq,dato,cmp);
    else
        return buscar_nodo(&(*pa)->der,dato,cmp);
}

/// vaciar arbol

void vaciar_arbol(t_arbol *pa)
{
    if(!*pa)
        return;
    vaciar_arbol(&(*pa)->izq);
    vaciar_arbol(&(*pa)->der);
    free(*pa);
    *pa=NULL;
}

/// podar hojas

void podar_hojas_arbol(t_arbol *pa)
{
    if(!*pa)
        return;
    if(ES_HOJA)
    {
        free(*pa);
        *pa=NULL;
        return;
    }
    podar_hojas_arbol(&(*pa)->izq);
    podar_hojas_arbol(&(*pa)->der);
}

 /// podar hojas desde nivel

 void podar_hojas_desde_nivel(t_arbol *pa,int n)
 {
     if(!*pa)
        return;
    if(n==0)
    {
        podar_hojas_arbol(pa);
        return;
    }
    podar_hojas_desde_nivel(&(*pa)->izq,n-1);
    podar_hojas_desde_nivel(&(*pa)->der,n-1);
 }
