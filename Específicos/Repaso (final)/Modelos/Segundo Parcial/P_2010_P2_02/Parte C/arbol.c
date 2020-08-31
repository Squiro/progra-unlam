#include "arbol.h"

int alturaArbol(t_arbol *pa)
{
    int altIzq, altDer;

    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    return altIzq > altDer ? altIzq + 1 : altDer + 1;
}

int arbolBalanceado(t_arbol *pa);
int esBalanceado(t_arbol *pa, int altura);

/*�rbol Binario Completo:
- Es un �rbol Binario en que todos sus nodos, salvo las hojas tienen sub�rbol por izquierda y tambi�n sub�rbol por derecha.  Es decir que es estrictamente binario.
- Adem�s todas sus hojas se encuentran al mismo nivel/alura/profundidad.

Con lo cual tiene 2 ^ (h - 1) - 1 nodos, o sea 2 ^ p - 1 nodos.

Teniendo en cuenta que las hojas estar�n a la altura m�xima ... lo que hablamos.*/

int arbolCompleto(t_arbol *pa)
{
    int altura = alturaArbol(pa);
    return esCompleto(pa, altura);
}
int esCompleto(t_arbol *pa, int altura)
{
    if (*pa)
    {
        return esCompleto(&(*pa)->izq, altura-1) && esCompleto(&(*pa)->der, altura-1);
    }
    return h == 0;
}

/**�rbol Balanceado:  dado un �rbol de altura/profundidad dada es balanceado si comprende un �rbol completo de altura/profundidad con una altura/profundidad uno menos que la propia.*/

int arbolBalanceado(t_arbol *pa)
{
   int altura = alturaArbol(pa);
   return esBalanceado(pa, altura);  /* invocando la funci'on que lo determina */
}

int esBalanceado(t_arbol *p, int altura)
{
   if(*pa)
   {
      return esBalanceado(&(*pa)->izq, altura - 1) && esBalanceado(&(*pa)->der, altura - 1);
   }
   return h <= 1;
}
