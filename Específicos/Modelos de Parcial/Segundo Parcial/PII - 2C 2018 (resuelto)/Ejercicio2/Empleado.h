#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Persona.h"

using namespace std;

class Empleado
{
  private:
    double sueldo;
    char cargo[50];
    Persona per;

  public:
    //Empleado(); //Por defecto
    Empleado(const Empleado &); //Por copia
    //Empleado(const double sueldo, const char * cargo, const Persona &per);
    Empleado(const double sueldo = 0, const char * cargo = NULL, const Persona &per = Persona());
    //Habria que haber hecho el param. por defecto

    //Operadores
    Empleado operator + (const int)const;
    //Falto hacer el operador igual
    Empleado & operator = (const Empleado &);
    friend ostream & operator << (ostream &, const Empleado &);
    friend istream & operator >> (istream &, Empleado &);
};

#endif // EMPLEADO_H_INCLUDED
