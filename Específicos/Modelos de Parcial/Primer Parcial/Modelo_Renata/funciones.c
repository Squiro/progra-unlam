#include "funciones.h"

int calcularSumaPolinomios()
{
    char str_poliP[1024], str_poliQ[1024];
    t_lista poliP, poliQ, resultado;

    crearLista(&poliP);
    crearLista(&poliQ);
    crearLista(&resultado);

    FILE * arch_res;

    arch_res = fopen("resultado.txt", "wt");

    if (!arch_res)
        return ERROR_ABRIR;

    leerPolinomio("polinomioP.txt", str_poliP, 1024);
    fprintf(arch_res, str_poliP);
    fprintf(arch_res, "\n+\n");
    leerPolinomio("polinomioQ.txt", str_poliQ, 1024);
    fprintf(arch_res, str_poliQ);
    fprintf(arch_res, "\n=\n");

    /*Esto se puede mejorar pero por ahora lo hacemos así. */
    guardarEnLista(&poliP, str_poliP);
    guardarEnLista(&poliQ, str_poliQ);
    sumarExpDuplicados(&poliP, compararTerminos);
    sumarExpDuplicados(&poliQ, compararTerminos);
    sumarPolinomios(&poliP, &poliQ, &resultado, compararTerminos);
    //recorrerLista(&resultado);

    guardarResultado(&resultado, arch_res);

    fclose(arch_res);

    return SUCCESS;
}

int leerPolinomio(const char * ruta, char * cadena, int tam)
{
    FILE * arch;

    arch = fopen(ruta, "rt");

    if (!arch)
        return ERROR_ABRIR;

    fgets(cadena, tam, arch);

    fclose(arch);

    return SUCCESS;
}

int guardarEnLista(t_lista * lista, char * polinomio)
{
    t_termino termino;

    while (*polinomio)
    {

        polinomio = mi_atoi(polinomio, &termino.coef);

        if (termino.coef == 0)
            termino.coef = 1;

        //printf("CADENA %s\n", polinomio);

        //Si la cadena quedó en una letra X, tenemos que obtener el exponente
        if (*polinomio == 'X')
        {
            //Salteamos la X
            polinomio++;
            //Es el siguiente simbolo el cosito del exponente? Si lo es, incrementamos el puntero de la cadena y obtenemos el exponente
            if (*polinomio == '^')
            {
                polinomio++;
                polinomio = mi_atoi(polinomio, &termino.exp);
            }
            else //Si no lo es, quiere decir que el exponente es 1
                termino.exp = 1;
        }
        else if (*polinomio == '+' || *polinomio == '-' || !(*polinomio))
        {
            termino.exp = 0;

            if (*polinomio)
                polinomio++;
        }

        //printf("COEF: %d  EXP: %d\n", termino.coef, termino.exp);
        insertarOrdenadoAsc(lista, &termino, compararTerminos);
    }

    return SUCCESS;
}

/** Este ATOI devuelve la posición de la cadena en donde encontró algo diferente a un digito */
char * mi_atoi(char * cadena, int * entero)
{
    int num = 0;
    int sign = 1;

    //En este caso particular, además de registrar si tenemos un -, registramos si tenemos un +, porque
    //así se me cantó hacer el algoritmo
    if (*cadena == '-')
    {
        sign = -1;
        cadena++;
    } else if (*cadena == '+')
    {
        cadena++;
    }

    while (*cadena - '0' >= 0 && *cadena - '0' <= 9)
    {
        num = num * 10 + (*cadena - '0');
        cadena++;
    }

    *entero = num*sign;

    return cadena;
}

//Recorre una lista y realiza la suma de aquellos terminos que tengan el mismo exponente. Actualiza uno de ellos y elimina el restante
int sumarExpDuplicados(t_lista * pl, t_cmp comparar)
{
    t_nodo * aux;
    //t_termino term;

    while (*pl)
    {
        aux = (*pl)->sig;

        while (aux)
        {
            if (comparar(&(*pl)->dato, &aux->dato) == 0)
            {
                //Sumamos los exponentes
                (*pl)->dato.coef += aux->dato.coef;
                (*pl)->sig = aux->sig;
                free(aux);
                aux = (*pl)->sig;
            }
            else
                aux = aux->sig;
        }

        pl = &(*pl)->sig;
    }

    return SUCCESS;
}

int sumarPolinomios(t_lista * poliP, t_lista * poliQ, t_lista * resultado, t_cmp comparar)
{
    int cmp;
    t_termino termino;

    while (*poliP && *poliQ)
    {
        //printf("P: %d Q: %d\n", (*poliP)->dato.coef, (*poliQ)->dato.coef);
        cmp = comparar(&(*poliP)->dato, &(*poliQ)->dato);

        //Si la comparacion es igual a 0, sumo los exponentes de cada uno y lo guardo en la lista nueva
        if (cmp == 0)
        {
            termino.coef = (*poliP)->dato.coef + (*poliQ)->dato.coef;
            termino.exp = (*poliP)->dato.exp;
            insertarOrdenadoAsc(resultado, &termino, compararTerminos);

            poliP = &(*poliP)->sig;
            poliQ = &(*poliQ)->sig;
        }
        else if (cmp < 0)
        {
            insertarOrdenadoAsc(resultado, &(*poliQ)->dato, compararTerminos);
            poliQ = &(*poliQ)->sig;;
        }
        else if (cmp > 0)
        {
            insertarOrdenadoAsc(resultado, &(*poliP)->dato, compararTerminos);
            poliP = &(*poliP)->sig;;
        }
    }

    while (*poliP)
    {
        insertarOrdenadoAsc(resultado, &(*poliP)->dato, compararTerminos);
        poliP = &(*poliP)->sig;
    }

    while (*poliQ)
    {
        insertarOrdenadoAsc(resultado, &(*poliQ)->dato, compararTerminos);
        poliQ = &(*poliQ)->sig;
    }

    return SUCCESS;
}

int guardarResultado(t_lista *pl, FILE * arch)
{
    int sign, primVuelta = 1;

    while (*pl)
    {
        if (primVuelta && (sign = (*pl)->dato.coef/(*pl)->dato.coef) != -1)
            fprintf(arch, "%dX^%d", (*pl)->dato.coef, (*pl)->dato.exp);
        else if ((*pl)->dato.exp != 0)
            fprintf(arch, "%+dX^%d", (*pl)->dato.coef, (*pl)->dato.exp);
        else
            fprintf(arch, "%+d", (*pl)->dato.coef);

        primVuelta = 0;
        pl = &(*pl)->sig;
    }

    return SUCCESS;
}

/** Devuelve la comparacion entre los exponentes */
int compararTerminos(const void *arg1, const void *arg2)
{
    t_termino * term1 = (t_termino *) arg1, * term2 = (t_termino *) arg2;

    return term1->exp-term2->exp;
}
