#ifndef MENU_H_
#define MENU_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbol.h"
#include "funciones.h"

void menu(t_arbol * pa, char * rutaAlum, char * rutaIdx);
void opciones(int op, t_arbol * pa, char * rutaAlum, char * rutaIdx);
#endif // MENU_H_
