#include "menu.h"

void menu(int num, t_arbol * pa)
{
    switch(num)
    {
        case 1: recorridos(pa);
        break;

        case 2: buscarClave(pa);
        break;

        case 3: guardarRecuperar(pa);
        break;

        case 4: contar(pa);
        break;

        case 5: cortar(pa);
        break;

        case 6: mostrarNodos(pa);
        break;

        case 7: busqueda(pa);
        break;

        case 8: poda(pa);
        break;
    }
}

void recorridos(t_arbol * arbol)
{
    printf("\n\n Mostrando en pre-orden recursivo... \n\n");
    preOrden(arbol, mostrar);
    printf("\n\n Mostrando en pre-orden iterativo... \n\n");
    preOrdenIterativo(arbol, mostrar);

    printf("\n\n Mostrando en in-orden recursivo... \n\n");
    inOrden(arbol, mostrar);
    printf("\n\n Mostrando en in-orden iterativo... \n\n");
    inOrdenIterativo(arbol, mostrar);

    printf("\n\n Mostrando en pos-orden recursivo... \n\n");
    posOrden(arbol, mostrar);
    printf("\n\n Mostrando en pos-orden iterativo... \n\n");
    posOrdenIterativo(arbol, mostrar);
}

void buscarClave(t_arbol * arbol)
{
    int arr[9] = { 1, 23, 44, 2, 4, 6, 99, 8, 10};

    printf("\n\n Buscando clave %d en el arbol... \n\n", arr[8]);
    printf("Resultado: %d\n", existeClave(arbol, &arr[8], compararEnteros));

    printf("\n\n Hallar dir de clave %d en el arbol... \n\n", arr[8]);
    printf("Resultado: %p\n", hallarDirClave(arbol, &arr[8], compararEnteros));

    printf("\n\n Hallar dir del padre de clave %d en el arbol... \n\n", arr[8]);
    printf("Resultado: %p\n", hallarDirPadreClave(arbol, &arr[8], compararEnteros));
    //t_nodo * aux = hallarDirPadreClave(&arbol, &arr[8], compararEnteros);
}

int guardarRecuperar(t_arbol * arbol)
{
    FILE * arch;

    arch = fopen("arbol.txt", "wt");

    if (!arch)
        return ERROR_ABRIR;

    guardar_arbol_txt(arbol, arch);

    fclose(arch);

    return SUCCESS;
}

void contar(t_arbol * arbol)
{
    printf("Nodos: %d\n", contarNodos(arbol));
    printf("Hojas: %d\n", contarHojas(arbol));
    printf("No Hojas: %d\n", contarNoHojas(arbol));
    printf("Pares: %d\n", contarCondicion(arbol, es_par));
    printf("Cant nodos subarbol derecho: %d\n", contarNodosSubarbolDerecho(arbol));
    printf("Mostrando nodos con hijos por izq...\n");
    printf("Cant nodos con hijos por izq: %d\n", contarHijosIzq(arbol));
    printf("Mostrando nodos hijos por der...\n");
    printf("Cant nodos con hijos por der: %d\n", contarHijosDer(arbol));
    printf("Mostrando nodos con hijos SOLO por izq...\n");
    printf("Cant nodos con hijos SOLO por izq: %d\n", contarHijosSoloIzq(arbol));
    printf("Mostrando nodos con hijos SOLO por der...\n");
    printf("Cant nodos con hijos SOLO por der: %d\n", contarHijosSoloDer(arbol));
}

void cortar(t_arbol * arbol)
{
    cortarHojas(arbol);
    printf("Nodos: %d\n", contarNodos(arbol));
}

void mostrarNodos(t_arbol * arbol)
{
    printf("Mostrando nodos en nivel 2: \n");
    mostrarNodosEnNivel(arbol, 2);
    printf("Mostrando nodos en altura 2: \n");
    mostrarNodosEnAltura(arbol, 2);
    printf("Mostrando hasta nivel 4 (inclusive): \n");
    mostrarNodosHastaNivel(arbol, 4, 0);
    printf("Mostrando hasta nivel 4 (no inclusive): \n");
    mostrarNodosHastaNivel(arbol, 4, 1);
    printf("Mostrando desde nivel 4 (inclusive): \n");
    mostrarNodosDesdeNivel(arbol, 4, 0);
    printf("Mostrando desde nivel 4 (no inclusive): \n");
    mostrarNodosDesdeNivel(arbol, 4, 1);
    printf("Mostrando altura del arbol: %d\n", alturaArbol(arbol));

}

void busqueda(t_arbol * arbol)
{
    printf("Busqueda de clave mayor en el arbol (trust me.): %d \n", buscarNodoClaveMayor(arbol));
    printf("Busqueda de clave menor en el arbol (trust me, again.): %d \n", buscarNodoClaveMenor(arbol));
    printf("Busqueda de dato mayor en el arbol: %d \n", buscarNodoMayorDato(arbol));
    printf("Busqueda de dato menor en el arbol: %d \n", buscarNodoMenorDato(arbol));
}

void poda(t_arbol * arbol)
{
    printf("Arbol sin podar: \n");
    inOrden(arbol, mostrar);
    printf("Podando hasta nivel 3...\n");
    podarHastaNivel(arbol, 3);
    inOrden(arbol, mostrar);
    printf("Podando hasta altura 7...\n");
    podarHastaAltura(arbol, 7);
    inOrden(arbol, mostrar);
}
