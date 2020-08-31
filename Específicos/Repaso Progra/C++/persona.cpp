#include "persona.h"

char * duplicaCadena(const char * str)
{
    if (str && *str)
    {
        try
        {
            char * aux = new char[strlen(str)+1];
            strcpy(aux, str);
            return aux;
        }
        catch (bad_alloc &err)
        {
            cerr << "Error: " << err.what();
        }
    }

    return NULL;
}

Persona :: Persona(const int dni, const char * apyn, const char sex)
{
    this->dni = dni;
    this->apyn = duplicaCadena(apyn);

    if (!this->apyn && apyn && *apyn)
            cerr << "Sin memoria" << endl;
    this->sex = sex;
}

Persona :: ~Persona()
{
    delete []apyn;
}

bool Persona :: operator == (const Persona &per)const
{
    return this->dni == per.dni && this->sex == per.sex && strcmp(this->apyn, per.apyn) == 0;
}

Persona & Persona :: operator = (const Persona &per)
{
    this->dni = per.dni;
    this->sex = per.sex;
    this->apyn = duplicaCadena(per.apyn);
    if (!this->apyn && per.apyn && *per.apyn)
        cerr << "Sin memoria" << endl;
    return *this;
}

ostream & operator << (ostream &salida, const Persona &per)
{
    salida << " Nombre: " << (per.apyn ? per.apyn : "Sin nombre") << " DNI: " << per.dni << " Sexo: " << per.sex << endl;
    return salida;
}

istream & operator >> (istream &entrada, Persona &per)
{
    char nombre[256];
    cout << "Ingrese el nombre: ";
    entrada >> nombre;
    per.apyn = duplicaCadena(nombre);
    if (!per.apyn && *nombre)
        cerr << "Sin memoria" << endl;
    cout << "Ingrese el DNI: ";
    entrada >> per.dni;
    cout << "Ingrese el sexo: ";
    entrada >> per.sex;

    return entrada;
}
