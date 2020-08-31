#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <iostream>
#include "persona.h"

using namespace std;

class Empleado
{
    private:
        double sueldo;
        char cargo[50];
        Persona per;

    public:
        Empleado(const double sueldo = 0, const char * cargo = NULL, const Persona &per = Persona());
        Empleado(const Empleado &);

        //Operadores
        Empleado operator + (const int)const;
        Empleado & operator = (const Empleado &);
        friend ostream & operator << (ostream &, const Empleado &);
        friend istream & operator >> (istream &, Empleado &);
};


#endif // EMPLEADO_H_
