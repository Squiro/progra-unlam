#include "funciones.h"

char * leerNum(char * ruta)
{
    FILE * arch;
    int size = 256, nextChar = 0;
    char * str = malloc(sizeof(char)*size);
    char c;

    arch = fopen(ruta, "rt");

    if (!arch)
    {
        fprintf(stderr, "Error archivo");
        exit(1);
    }

    while ((c = fgetc(arch)) != EOF)
    {

        if (nextChar >= size-1)
        {
            size *= 2;
            str = realloc(str, size);
            if (!str)
            {
                fprintf(stderr, "Sin memoria");
                exit(1);
            }
        }

        str[nextChar++] = c;
    }

    str[nextChar] = '\0';

    return str;
}

int guardarEnPila(t_pila *p, char *str)
{
    char *pIni = str;
    int num;

    vaciarPila(p);

    while (*pIni && !pilaLlena(p))
    {
        num = *pIni - '0';
        apilar(p, &num);
        pIni++;
    }

    if (*pIni)
    {
        fprintf(stderr, "El num. excede el tam. de la pila. No se pudieron guardar %s", pIni);
        exit(1);
    }

    return SUCCESS;
}

int sumarPilas(t_pila *pila1, t_pila *pila2, t_pila *pila3)
{
    int num1, num2, res, carry = 0;

    vaciarPila(pila3);

    if (pilaVacia(pila1) || pilaVacia(pila2))
        return -1;

    while (!pilaVacia(pila1) && !pilaVacia(pila2))
    {
        if (desapilar(pila1, &num1))
            num1 = 0;
        if (desapilar(pila2, &num2))
            num2 = 0;

        res = num1+num2+carry;
        carry = res/10;
        res = res%10;
        apilar(pila3, &res);
    }

    if (carry)
        apilar(pila3, &carry);

    return SUCCESS;
}

char * stackToStr(t_pila *p)
{
    int num, count = 0, size = 256;
    char * str = malloc(sizeof(char)*size);

    while (!pilaVacia(p))
    {
        desapilar(p, &num);

        if (count >= size-1)
        {
            str = realloc(str, size*2);

            if (!str)
            {
                fprintf(stderr, "Sin memoria");
                exit(1);
            }
        }

        str[count] = num + '0';
        count++;
    }

    str[count] = '\0';

    return str;
}
