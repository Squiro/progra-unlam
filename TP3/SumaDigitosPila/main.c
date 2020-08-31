#include "funciones.h"

//Ejercicio
//Leer dos numeros, cada uno contenido en un archivo de texto
//Guardar la suma de ambos en un archivo de texto

int main()
{
    char num1[512], num2[512];
    int x;
    t_pila pila1, pila2, pila3;
    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila3);

    leerNum("num1.txt", num1);

    leerNum("num2.txt", num2);

    guardarEnPila(num1, &pila1);
    guardarEnPila(num2, &pila2);
    sumarPilas(&pila1, &pila2, &pila3);
    ver_tope(&pila3, &x);
    printf("El tope es: %d\n", x);
    stackToFile("res.txt", &pila3);

    /*//Apilar todo,

    int x = 1;
    while(apilar(&p, x)){
     x++;
    }

    //ver tope
    ver_tope(&p, &x);
    printf("El tope es: %d\n", x);


    //desapilar todo
    while(desapilar(&p, &x)){
        printf("Desapilando: %d\n", x);
    }*/
    return 0;
}
