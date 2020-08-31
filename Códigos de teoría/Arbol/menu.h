#ifndef MENU_H_
#define MENU_H_

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

void menu(int num, t_arbol * pa);
void recorridos(t_arbol * arbol);
void buscarClave(t_arbol * arbol);
int guardarRecuperar(t_arbol * arbol);
void contar(t_arbol * arbol);
void cortar(t_arbol * arbol);
void mostrarNodos(t_arbol * arbol);
void busqueda(t_arbol * arbol);
void poda(t_arbol * arbol);

#endif // MENU_H_
