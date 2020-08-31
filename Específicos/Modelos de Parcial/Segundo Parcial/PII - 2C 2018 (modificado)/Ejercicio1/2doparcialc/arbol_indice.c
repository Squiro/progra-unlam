#include "arbol_indice.h"

void crear_arbol_indice(t_arbol_indice * pa)
{
    *pa = NULL;
}

int insertarEnArbolIndice(t_arbol_indice * pa, const t_indice* pd, t_comp comparar)
{
    int comp;

    if (*pa)
    {
        comp = comparar(&(*pa)->idx, pd);

        if (comp < 0)
            insertarEnArbolIndice(&(*pa)->pder, pd, comparar);
        else if (comp > 0)
            insertarEnArbolIndice(&(*pa)->pizq, pd, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        *pa = (t_nodo_arbol_indice *) malloc(sizeof(t_nodo_arbol_indice));

        if (!(*pa))
            return SIN_MEM;

        (*pa)->idx = *pd;
        (*pa)->pizq = NULL;
        (*pa)->pder = NULL;
    }

    return TODO_OK;
}

void recorrer_arbol_enorden_inverso(const t_arbol_indice * pa, t_acc accion, void* datos_accion)
{
  if (*pa)
  {
    recorrer_arbol_enorden_inverso(&(*pa)->pder, accion, datos_accion);
    accion(&(*pa)->idx, datos_accion);
    recorrer_arbol_enorden_inverso(&(*pa)->pizq, accion, datos_accion);
  }
}

void mostrar(t_indice* idx, void* datos_accion)
{
    printf("Nombre: %s", idx->apyn);
    printf("\nNumReg: %d", idx->numReg);
    printf("\n\n");
}

