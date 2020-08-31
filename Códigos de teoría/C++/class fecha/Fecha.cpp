#include "Fecha.h"
#include <iostream>
using namespace std;
#include "stdio.h"

Fecha::Fecha()
{
    this->dia=1;
    this->mes=1;
    this->anio=1900;
}

Fecha::~Fecha()
{
    //dtor
}
Fecha:: Fecha(const int d,const int m,const int a)
{
    this->dia=d;
    this->mes=m;
    this->anio=a;
}
Fecha::Fecha(const Fecha &obj)
{
    dia=obj.dia;
    mes=obj.mes;
    anio=obj.anio;
}
void Fecha:: mostrarFecha()
{
        cout<<" fecha Nacimiento: "<< dia <<" "<< mes <<" "<< anio <<endl;

}
ostream& operator<<(ostream& salida, const Fecha &obj)
{
    salida<<"Dia: "<<obj.dia << " Mes: "<<obj.mes<<" Anio: "<<obj.anio<<endl;
    return salida;
}

istream & operator>>(istream &entrada ,Fecha &obj)
{
    cout<<"Ingrese dia: ";
    entrada>>obj.dia;
    cout<<"Ingrese mes: ";
    entrada>>obj.mes;
    cout<<"Ingrese anio: ";
    entrada>>obj.anio;
    return entrada;
}

