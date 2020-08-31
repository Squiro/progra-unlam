#include "empleado.h"

Empleado :: Empleado(const double sueldo, const char * cargo, const Persona &per)
{
    this->sueldo = sueldo;

    if (cargo)
        strcpy(this->cargo, cargo);
    else
        *this->cargo = '\0';
    this->per = per;
}

Empleado :: Empleado(const Empleado &obj)
{
    this->sueldo = obj.sueldo;
    this->per = obj.per;

    if (obj.cargo)
        strcpy(this->cargo, obj.cargo);
    else
        *this->cargo = '\0';
}

Empleado Empleado :: operator + (const int num)const
{
    Empleado aux(this->sueldo+num, this->cargo, this->per);
    return aux;
}

Empleado & Empleado :: operator = (const Empleado &obj)
{
    this->sueldo = obj.sueldo;
    if (obj.cargo)
        strcpy(this->cargo, obj.cargo);
    else
        *this->cargo = '\0';
    this->per = obj.per;

    return *this;
}

ostream & operator << (ostream &salida, const Empleado &obj)
{
    salida << "Sueldo: " << obj.sueldo << " Cargo: " << (*obj.cargo ? obj.cargo : "Sin cargo") << obj.per;
    return salida;
}

istream & operator >> (istream &entrada, Empleado &obj)
{
    cout << "Ingrese el sueldo: ";
    entrada >> obj.sueldo;
    cout << "Ingrese el cargo: ";
    entrada >> obj.cargo;
    entrada >> obj.per;

    return entrada;
}
