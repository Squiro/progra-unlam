#include "funciones.h"

/*
    TIPO DE DATO ABSTRACTO:

    TDA -> estructura

    Los TDA tienen operaciones implementadas.
    No me interesa en sí la estructura del TDA. Lo unico que me importa son las operaciones (primitivas/funciones) que
    trabajan con ese TDA.
*/

/*
    PILA:

    Las pilas trabajan de forma LIFO (last in, first out). En una pila, el ultimo entrar es el primero en salir.
    Las pilas no se pueden recorrer. Lo unico que puedo ver es lo ultimo que ingresé.

    En el main, lo primero que hacemos es:
    t_pila pila; -> SIEMPRE la creamos así

    Primitivas para pila:
    -void crear/inicializarPila(t_pila *p); -> limpia la memoria para poder guardar datos en la pila, la acondicionamos
        /!\ Siempre hay que inicializar la pila, la lista, LO QUE SEA

    -int pilaLlena(const t_pila *p); -> verifica si la pila está llena o no

    -int apilar(t_pila *p, const t_dato *d); -> retorna si pudo o no pudo apilar

    -int verTope(const t_pila *p, t_dato *d); -> retorna si se pudo o no ver el tope (si existe o no).
        El segundo param es donde se va a guardar el dato.

    -int desapilar(t_pila *p, t_dato *d); -> retorna si se pudo desapilar o no (chequea que se pueda desapilar).

    -int pilaVacia(const t_pila *p); -> verifica si la pila está vacía o no

    -void vaciarPila(t_pila *p); -> vacia la pila entera, no puede fallar.

    // Notacion

    Parametros de entrada: solamente me dan info (constantes, const)
    Parametros de salida: sacan informacion
*/

/*
    SOBRE PRIMITIVAS DE PILAS

    -Tope: el tope nos sirve para saber en donde tengo que poner el siguiente dato.
           Nos marca la cantidad de elementos cargados.
           Nos puede indicar la primera posición libre, o la última ocupada. Eso lo decidimos.
           • Primera pos libre: si la pila está vacía, devuelve 0 (esto nos puede servir para la primitiva
           pila vacía). Si no, devuelve la primera posición libre. La pila estaría llena cuando el tope == TAM (chequeo de pila llena).
           Vamos a usar esta porque le gusta a Renata.
           • Ultima pos ocupada: la pila estaría llena cuando tope == TAM-1. El tope comienza desde -1.
*/

//Ejercicio
//Leer dos numeros, cada uno contenido en un archivo de texto
//Guardar la suma de ambos en un archivo de texto

int main()
{
    char num1[512], num2[512];
    t_pila pila1, pila2, pila3;
    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pila3);

    leerNum("num1.txt", num1);

    leerNum("num2.txt", num2);

    guardarEnPila(num1, &pila1);
    guardarEnPila(num2, &pila2);
    sumarPilas(&pila1, &pila2, &pila3);
    stackToFile("res.txt", &pila3);

    return 0;
}
