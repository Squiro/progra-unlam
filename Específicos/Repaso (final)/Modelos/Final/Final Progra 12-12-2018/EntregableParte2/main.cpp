
#include "main.h"



int main(void)
{
    calcular(6, 5, 4, 3, 2);

    return 0;
}

void calcular(int nUno, int nDos, int nTre, int nCua, int nCin)
{
   Caja     c0,               // caja de 1 x 1 x 1
            c1(nUno),         // cubo de nUno de arista
            c2(nUno, nDos),   // caja de base nUno x nDos y altura nDos
            c3(nTre, nCua, nCin);

   cout << "Valores iniciales:" << endl
        << "c0 = " << c0 << endl << "c1 = " << c1 << endl
        << "c2 = " << c2 << endl << "c3 = " << c3 << endl;

   c0 = nCin * c3;         // calcula nCin por cada dimensión
   c1 = c2++;              // se incrementan en uno sus dimensiones
   c3 = --c2;              // se decrementan en uno sus tres dimensiones

   cout << "Valores finales:" << endl
        << "c0 = " << c0 << endl << "c1 = " << c1 << endl
        << "c2 = " << c2 << endl << "c3 = " << c3 << endl;
}

