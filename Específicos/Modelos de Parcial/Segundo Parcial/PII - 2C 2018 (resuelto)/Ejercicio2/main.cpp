#include <iostream>
#include "Persona.h"
#include "Empleado.h"

using namespace std;

int main()
{
    Empleado e1;
    Empleado e2(e1);
    Persona p1(35674325,"Federico",'M'),p2(p1);
    cout << "EMPLEADO 1"<<endl<<e1 <<endl<<endl;
    cout << "EMPLEADO 2"<<endl<<e2 <<endl<<endl;
    Empleado e3(1000,"Obrero",p1);
    cout << "EMPLEADO 3"<<endl<< e3<<endl;
    e2 = e3;
    cout << "EMPLEADO 2"<<endl<<e2 <<endl<<endl;
    Empleado e4;
    cin >> e4;
    cout << "EMPLEADO 4"<<endl<<e4 <<endl<<endl;
    if (p2==p1)
        e3= e3+10000;
    cout << e3;
    return 0;

}

