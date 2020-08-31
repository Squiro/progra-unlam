#include "Empleado.h"

/*Empleado :: Empleado()
{
    *this->cargo = '\0';
    this->sueldo = 0;
    //this->per= Persona(); no haria falta
}*/

Empleado :: Empleado(const Empleado &obj)
{
    this->sueldo = obj.sueldo;
    this->per = obj.per;
    strcpy(this->cargo, obj.cargo);
}

Empleado :: Empleado(const double sueldo, const char * cargo, const Persona &per)
{
    this->sueldo = sueldo;
    if (cargo)
    {
        strncpy(this->cargo, cargo, sizeof(this->cargo)-1);
    }
    else
        *this->cargo = '\0';
    this->per = per;
}

Empleado Empleado :: operator + (const int num)const
{
    Empleado aux(this->sueldo+num, this->cargo, this->per);
    return aux;
    //return Empleado(this->sueldo+num, this->cargo, this->per);
}

Empleado & Empleado :: operator = (const Empleado &obj)
{
    this->sueldo = obj.sueldo;
    strcpy(this->cargo, obj.cargo);
    this->per = obj.per;

    return *this;
}

ostream & operator << (ostream &salida, const Empleado &emp)
{
    salida << "Sueldo: " << emp.sueldo << " Cargo: " << (*emp.cargo ? emp.cargo : "Sin cargo") << emp.per;

    return salida;
}

istream & operator >> (istream &entrada, Empleado &emp)
{
    cout << "Ingrese el sueldo: ";
    entrada >> emp.sueldo;
    cout << "Ingrese el cargo: ";
    entrada >> emp.cargo;
    entrada >> emp.per;

    return entrada;
}
