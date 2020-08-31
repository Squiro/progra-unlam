#ifndef FECHA_H
#define FECHA_H
using namespace std;
#include <iostream>


class Fecha
{
    public:
        //Constructores
        Fecha();
        ~Fecha();
        Fecha(const int,const int,const int);
        Fecha(const Fecha &obj);

        //Metodos
        void mostrarFecha();

        //Operadores
        //Fecha & operator = (const Fecha &); no es necesario porque estamos laburando con memoria estatica
        friend ostream& operator<<(ostream&,const Fecha&);  //sale
        friend istream& operator>>(istream&, Fecha &);   //permite el


    private:
        int dia;
        int mes;
        int anio;

};

#endif // FECHA_H
