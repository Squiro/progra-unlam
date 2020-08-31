#include <iostream>
#include "punto.h"

using namespace std;

int main()
{
    //El compilador es el que reserva memoria para el objeto.
    Punto p1;
    Punto p2(3, 4);
    Punto p3(1,2);
    Punto p5;

    cout << "Mostrando p1 y p2" << endl;
    p1.mostrar();
    p2.mostrar();
    cout << "Mostrando p4 copia de p2" << endl;
    Punto p4(p2);
    p4.mostrar();
    p1 = p4;
    cout << "Mostrando p1 con operador = p4" << endl;
    p1.mostrar();
    p2 += p1;
    cout << "Mostrando p2 con += p1" << endl;
    p2.mostrar();
    p4 = p1 + p2;
    cout << "Mostrando p4 = p1 + p2" << endl;
    p4.mostrar();
    p3 -= p2;
    cout << "Mostrando p3 -= p2" << endl;
    p3.mostrar();
    p4 = p2-2;
    cout << "Mostrando p4 = p2 -2" << endl;
    p4.mostrar();
    p4 = p3++;
    cout << "Mostrando p4 = p3++" << endl;
    p4.mostrar();
    cout << "Mostrando p4 = ++p3" << endl;
    p4 = ++p3;
    p4.mostrar();

    if (p4 == p3)
        cout << "p4 es igual a p3" << endl;
    else
        cout << "p4 es diferente a p3" << endl;

    if (p4 > p3)
        cout << "p4 es mayor que p3" << endl;
    else
        cout << "p4 es menor que p3" << endl;
    p4 = p3 +2;
    p5 = 2 + p3;

    if (p4 == p5)
        cout << "p4 es igual a p5" << endl;

    p5.setX(2);
    cout << "Mostrando getX de p5: " << p5.getX() << endl;
    p5.setY(2);
    cout << "Mostrando getY de p5: " << p5.getY() << endl;

    return 0;
}
