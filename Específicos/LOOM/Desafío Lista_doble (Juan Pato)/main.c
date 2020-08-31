#include "header.h"
int main()
{
    t_dato datos[10]={
    {"Buenos Aires","CABA","jorge",2},
    {"Cordoba","fafafa","luis",7},
    {"San luis","mee","alberto",2},
    {"Buenos Aires","CABA","jose",1},
    {"Corrientes","mar","raul",4},
    {"Entre Rios","sal","miguel",2},
    {"Buenos Aires","CABA","jose",3},
    {"Cordoba","fafafa","luis",2},
    {"San Luis","mee","alberto",4},
    {"Corrientes","fag","a",1},
    };
    int i=0;
    t_lista lista;
    crear_lista(&lista);


    for(i=0;i<10;i++)
    {
        insertarDesordenado(&lista,&datos[i]);
       //insertarListaDobleOrdenada(&lista,&datos[i],comparaProvCiu);
    }
    mostrarLista(&lista);
    ordenarListaDoble(&lista,comparaProvCiu);

    printf("\nLista ordenada: \n");
    mostrarLista(&lista);

    recorreYactualiza(&lista);
   /* printf("\nLista actualizada: \n");
    mostrarLista(&lista);*/

    printf("\nLista con totales y sin duplicados: \n");
    recorreYborraDuplis(&lista);
    mostrarLista(&lista);




    return 0;
}
