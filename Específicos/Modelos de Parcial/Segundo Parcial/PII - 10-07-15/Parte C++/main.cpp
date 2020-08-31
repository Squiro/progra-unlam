#include <iostream>
#include "producto.h"
#include "bulto.h"

using namespace std;

int main()
{

    Producto p1("Heladera", 180, 70, 70);
    Producto p2("Microondas", 40, 20, 20);
    Producto p3("Celular", 10, 2, 15);
    Bulto bx = p1 + p2 + p3;
    cout << bx.getDesc() << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << bx << endl;
    cout << bx.getVol() << endl;
    return 0;
}
