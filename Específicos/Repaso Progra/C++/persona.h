#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
    private:
        int dni;
        char * apyn;
        char sex;

    public:
        Persona(const int dni = 0, const char * apyn = NULL, const char sex = 'A');
        ~Persona();


        //Operadores
        bool operator == (const Persona &)const;
        Persona & operator = (const Persona &);
        friend ostream & operator << (ostream &, const Persona &);
        friend istream & operator >> (istream &, Persona &);


};

#endif // PERSONA_H_
