#include <iostream>
#include "persona.h"
#include "Fecha.h"

using namespace std;

int main()
{
    Fecha f1(10, 10, 1987);
    Persona p2(12345678, 'M', "Hola", "Pepe", f1);

    //p2.mostrar();
    cout << p2;
    Persona p1;
    p1 = p2;
    cout << p1;

    Persona p4;

    cin >> p4;

    return 0;
}
