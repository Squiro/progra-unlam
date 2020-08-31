#include "header.h"
int comparaProvCiu(const void *d1,const void *d2)
{
    t_dato * dat1=(t_dato*)d1;
    t_dato * dat2=(t_dato*)d2;
    if(strcmp(dat1->pci,dat2->pci)==0)
        return strcmp(dat1->ciu,dat2->ciu);
    else
        return strcmp(dat1->pci,dat2->pci);
}
void crear_lista(t_lista * pl)
{
    *pl=NULL;
}

t_nodo * buscar_menor(t_nodo * act,t_cmp cmp)
{
    t_nodo * pmenor=act;
    while(act)
    {
        if(cmp(&act->dato,&pmenor->dato)<0)
            pmenor=act;
        act=act->sig;
    }
    return pmenor;
}
void intercambio(t_nodo ** act, t_nodo ** pmenor)
{
    t_nodo * actSig=(*act)->sig;
    t_nodo * actAnt=(*act)->ant;
    t_nodo * menorAnt=(*pmenor)->ant;
    t_nodo * menorSig=(*pmenor)->sig;

    if(menorAnt!=*act)
    {
        (*pmenor)->ant=actAnt;
        (*pmenor)->sig=actSig;
        actSig->ant=(*pmenor);
        if(actAnt)
            actAnt->sig=(*pmenor);

        (*act)->sig=menorSig;
        (*act)->ant=menorAnt;
        menorAnt->sig=(*act);
        if(menorSig)
            menorSig->ant=(*act);
    }
    else
    {
        (*pmenor)->ant=actAnt;
        if(actAnt)
            actAnt->sig=(*pmenor);
        (*pmenor)->sig=(*act);

        (*act)->ant=(*pmenor);
        (*act)->sig=menorSig;
        if(menorSig)
            menorSig->ant=(*act);
    }
    *act=*pmenor;
}

int ordenarListaDoble(t_lista * pl,t_cmp cmp)
{
    t_nodo * act=*pl,*pmenor;

    if(!act)
        return LISTA_VACIA;

    while(act->ant)/*voy al inicio de la lista*/
        act=act->ant;
    while(act)
    {
        pmenor=buscar_menor(act,cmp);
        if(pmenor!=act)
            intercambio(&act,&pmenor);

        act=act->sig;
    }
    return TODO_OK;
}

int insertarDesordenado(t_lista * pl,const t_dato * d)
{
    t_nodo * nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;
    t_nodo *act=*pl,*ant,*sig;
    if(!act)
    {
        ant=sig=NULL;
    }
    else
    {
        ant=act;
        sig=act->sig;
    }

    if(sig)
        sig->ant=nue;

    if(act)
        act->sig=nue;

    nue->dato=*d;
    nue->ant=ant;
    nue->sig=sig;

    *pl=nue;
    return TODO_OK;
}

void mostrarLista(const t_lista * pl)
{
    t_nodo * act=*pl;
    if(!act)
        return;
    while(act->ant)
        act=act->ant;
    while(act)
    {
        printf("Provincia %-10s\tCiudad %-8s\t %-8s \tCant Hab: %d\n",act->dato.pci,act->dato.ciu, act->dato.loc, act->dato.cantH);
        act=act->sig;
    }
}

int insertarListaDobleOrdenada(t_lista *pl, const t_dato *d,t_cmp compara)
{
    t_nodo * act, *auxAnt, *auxSig, *nue;
    act=*pl;

    if(act)
    {
        while(act->sig && compara(d,&(*pl)->dato)>0)
            act=act->sig;

        while(act->ant && compara(d,&(*pl)->dato)<0)
            act=act->ant;

        if(compara(d,&(*pl)->dato)>0)
        {
            auxAnt=act;
            auxSig=act->sig;
        }
        else
        {
            auxSig=act;
            auxAnt=act->ant;
        }
    }
    else
    {
        auxAnt=auxSig=NULL;
    }
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return SIN_MEM;

    nue->dato=*d;
    nue->ant=auxAnt;
    nue->sig=auxSig;

    if(auxAnt)
        auxAnt->sig=nue;
    if(auxSig)
        auxSig->ant=nue;

    *pl=nue;

    return TODO_OK;
}

int recorreYactualiza(t_lista *pl)
{
    t_nodo * act = *pl;
    t_nodo * pri;
    t_dato aux;

    if(!act)
        return LISTA_VACIA;


    while(act->ant)
        act=act->ant;//me paro en el primero de la lista
    pri=act;//guardo la pos del primero

    aux=act->dato;
    act=act->sig;
    while(act)
    {
        strcpy(pri->dato.loc,"TOTAL");
        if(strcmp(aux.ciu,act->dato.ciu)==0)
        {
            pri->dato.cantH+=act->dato.cantH;
            act=act->sig;
        }
        else
        {
            pri=act;
            aux=act->dato;
            act=act->sig;
        }

    }
    strcpy(pri->dato.loc,"TOTAL");
    return TODO_OK;
}

int recorreYborraDuplis(t_lista *pl)
{
    t_nodo * act= *pl;
    t_nodo * elim;
    t_nodo * pri;
    if(!act)
        return LISTA_VACIA;

    while(act->ant)
        act=act->ant;
    pri=act;
    act=act->sig;
    while(act)
    {
        if(strcmp(act->dato.ciu,pri->dato.ciu)==0)
        {
            //borro el nodo act y engancho (el pri con el act->sig)
            elim=act;
            if(act->sig)
                act->sig->ant=pri;
            pri->sig=act->sig;
            act=act->sig;
            free(elim);
        }
        else
        {
            pri=act;
            act=act->sig;
        }
    }
    return TODO_OK;
}
