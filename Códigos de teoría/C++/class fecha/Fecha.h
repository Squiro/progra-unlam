#ifndef FECHA_H
#define FECHA_H
using namespace std;
#include <iostream>


class Fecha
{
    public:
        Fecha();
        ~Fecha();
        Fecha(const int,const int,const int);

        Fecha(const Fecha &obj);
        void mostrarFecha();
        friend ostream& operator<<(ostream&,const Fecha&);  //sale
        friend istream& operator>>(istream&, Fecha &);   //permite el ingreso

    private:
        int dia;
        int mes;
        int anio;

};

#endif // FECHA_H
