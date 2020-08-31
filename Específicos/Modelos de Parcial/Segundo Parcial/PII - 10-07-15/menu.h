#ifndef MENU_H_
#define MENU_H_

#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

void menu(t_arbol * pa, char * rutaAlum, char * rutaIdx);
int seleccion(int num, t_arbol * pa, char * rutaAlum, char * rutaIdx);

#endif // MENU_H_



