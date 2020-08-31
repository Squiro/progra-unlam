#include <iostream>
#include "hora.h"

using namespace std;

int main()
{

    Hora h1(10,21,10);
    h1.mostrar();

    Hora h2(h1);

    h2.mostrar();

    //RECORDAR: no es necesario hacer el operador = si estamos en memoria estatica. El compilador se encarga.
    Hora h3 = h1 + h2;
    h3.mostrar();

    Hora h4 = h1 + 3600;
    h4.mostrar();

    if (h1 > h2)
        cout << "H1 es mayor" << endl;
    else
        cout << "H2 es mayor" << endl;

    h3 = h2++;
    h4 = ++h2;

    h3.mostrar();
    h4.mostrar();

    cout << h1;

    Hora::setFormato(Hora::formatoAmPm);

    cout << h1;
    return 0;
}
