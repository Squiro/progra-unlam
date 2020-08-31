#include <stdio.h>
#include <stdlib.h>
#define TAM1 10
#define TAM2 50
#define TAM_VEC 10 //Notar la convencion, se escriben con mayuscula y con underscore para separar
#define CUAD(x) (x)*(x) //Puedo pasarle un parametro a los macros
#define SUMA(x,y) ((x) + (y))
#define CUBO(x) CUAD(x) //Macro de una macro

/*#define FACTORIAL(x) int i, res = x; \
if (x==0) printf("%d", 1); \
else                    \
{                       \
    for (i = x; i > 1 ; i--) \
    {                       \
        res*=(i-1);         \
                        \
    }                       \
    printf("%d", res);  \
}*/

/*#define FACTORIAL(x) res = x, num = x;\
if (x==0) printf("%d", 1); \
else                    \
{                       \
    while (num > 1) \
    {                       \
       res *= (num-1);         \
        (num--);                \
    }                       \
    printf("%d", res);  \
}*/

#define FACTORIAL(x, fac) fac=1; int i;\
for (i=x; i > 0; i--) \
{                       \
    fac*=i;      \
}

int main()
{
    int x = 2, y = 3, res = 0, num = 0, fac = 0;
    printf("%d\n", CUAD(x));
    printf("%d\n", CUAD(x+3)); //El reemplazo ES LITERAL. Esto va a poner (y + 3) * (y + 3) si esta def como CUAD(x) x*x
    printf("%d\n", SUMA(x,y));
    printf("%d\n", SUMA(x,y)*3); //EL REEMPLAZO ES LITERAL JA. Entonces (x) + (y) * 3
    FACTORIAL(5, fac)
    printf("%d", fac);

    return 0;
}

//HACER MACROS DE:
/*
Parte entera
Redondedo (1,23 = 1; 1,65 = 2)
Valor absoluto
Parte decimal
Intercambio (cambiar x a y, y a x)
Menor
Mayor
*/
