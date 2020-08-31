#pragma once
#include <iostream>
#include "Fecha.h"


using namespace std;

class Persona
{
    private:
        long dni;
        char sexo;
        char nombre[20];
        char *apellido;
        Fecha fnac;

    public:
        //Constructores
        Persona();
        Persona(const long dni, const char sexo, const char *nombre, char *apellido, const Fecha &fnac);
        Persona(const Persona &);

        //Destructor
        ~Persona();

        //Métodos
        void mostrar();

        //Operadores
        Persona & operator = (const Persona &);
        friend ostream & operator << (ostream &, const Persona &);
        friend istream & operator >> (istream &, Persona &);


};
