#include "funciones.h"
int leerNum(char * ruta, char *str)
{
    FILE * arch;

    arch = fopen(ruta, "rt");

    if (!arch)
        return ERROR_ABRIR;

    fscanf(arch, "%s", str);

    fclose(arch);

    return TODO_BIEN;
}

int guardarEnPila(char *str, t_pila *pila)
{
    char *pLec = str;
    t_dato d;

    vaciarPila(pila);

    while (*pLec && !pilaLlena(pila))
    {
        *pLec-='0';
        d=*pLec;
        apilar(pila, &d);
        pLec++;
    }

    if (*pLec)
    {
        printf("El numero excede el tamaño de la pila... No se pudieron guardar: %s", pLec);
        return ERROR_APILAR;
    }

    return 0;
}


int sumarPilas(t_pila *pila1, t_pila *pila2, t_pila *pila3)
{
    t_dato num1, num2;
    int res, carry = 0;
    vaciarPila(pila3);

    if (pilaVacia(pila1) || pilaVacia(pila2))
    {
        printf("Una de las pilas a sumar se encuentra vacia.");
        return ERROR_SUMA;
    }

    while (!pilaVacia(pila1) && !pilaVacia(pila2))
    {
        /* Si aplicamos esta forma, no hace falta hacer los whiles de adelante
        if(!desapilar(pila1, &num1)
            num1 = 0;
        if(!desapilar(pila2, &num2)
            num2= 0;
        */

        //Desapilamos los numeros que necesitamos para la suma
        desapilar(pila1, &num1);
        desapilar(pila2, &num2);
        //Sumamos teniendo en cuenta el carry anterior
        res = num1 + num2 + carry;
        //Dividimos el resultado de la suma por 10 para obtener el carry (1 o 0)
        carry = res/10;
        //Aplicamos modulo de 10 a la suma para obtener un numero de 1 digito (de 0 a 9)
        res = res%10;
        //Apilamos en la tercer pila el resultado de la suma (unico digito)
        apilar(pila3, &res);
    }

    //Si salimos del primer while y la pila1 sigue estando llena, quiere decir que todavía nos quedan elementos que sumar
    //pero que la otra pila ya terminó
    while(!pilaVacia(pila1))
    {
        desapilar(pila1, &num1);
        res = num1 + carry;
        carry = res/10;
        res = res%10;
        apilar(pila3, &res);
    }

    //Si salimos del primer while y la pila2 sigue estando llena...
    while(!pilaVacia(pila2))
    {
        desapilar(pila2, &num2);
        res = num2 + carry;
        carry = res/10;
        res = res%10;
        apilar(pila3, &res);
    }

    if (carry)
        apilar(pila3, &carry);

    return 0;
}

int stackToFile(char *ruta, t_pila *pila)
{
    FILE * arch;
    char datos[512];

    arch = fopen(ruta, "wt");

    if (!arch)
        return ERROR_ABRIR;

    stackToStr(datos, pila);

    fprintf(arch, "%s", datos);

    fclose(arch);

    return 0;
}

int stackToStr(char *str, t_pila *pila)
{
    int num;
    char *pLec = str;

    while (!pilaVacia(pila))
    {
        desapilar(pila, &num);
        *pLec = num + '0';
        pLec++;
    }

    *pLec = '\0';

    return 0;
}
