#include "persona.h"
#include <string.h>
#include <stdio.h>

char * duplicaCadena(const char * cad)
{
    if (cad && *cad)
    {
        try
        {
            char * aux = new char[strlen(cad)+1];
            strcpy(aux, cad);
            return aux;
        }
        catch (bad_alloc &error)
        {
            cerr << "Error: " << error.what(); //Es como un cout para mostrar errores
        }
    }
    return NULL;
}

/** CONSTRUCTORES */

Persona :: Persona()
{
    this->dni = 0;
    this->sexo = '\0';
    strcpy(this->nombre, "nn");
    apellido = NULL; //Las variables dinamicas las inicializamos con null
    Fecha fxDef;
    this->fnac = fxDef;
}

Persona :: Persona(const long dni, const char sexo, const char *nombre, char *apellido, const Fecha &fnac)
{
    this->dni = dni;
    this->sexo = sexo;

    if (nombre)
    {
        strncpy(this->nombre, nombre, sizeof(this->nombre)-1); //Copiamos hasta un caracter menos, evitando asi el overflow
        this->nombre[sizeof(this->nombre)] = '\0'; //le metemos el null terminator
        //this->nombre[strlen(nombre)+1] = '\0'; Alternativamente, para evitar espacios en blancos
    }
    else
        *this->nombre = '\0';

    this->apellido = duplicaCadena(apellido);

    if (!this->apellido && apellido && *apellido)
        cerr << "Sin memoria en constructor parametrizado";

    this->fnac = fnac;
}

Persona :: Persona(const Persona &obj)
{
    this->dni = obj.dni;
    this->sexo = obj.sexo;
    strcpy(this->nombre, obj.nombre);
    this->apellido = duplicaCadena(obj.apellido);
    if (!this->apellido && obj.apellido && *obj.apellido)
        cerr << "Sin memoria en constructor por copia";
    this->fnac = obj.fnac;
}

/** DESTRUCTOR */
//~ = alt+126
Persona :: ~Persona()
{
    delete []apellido;
}

/** MÉTODOS */
void Persona :: mostrar()
{
    cout << "DNI: " << this->dni << endl << "Sexo: " << this->sexo << endl << "Nom: " << (*nombre ? nombre : "Sin nombre") << endl << "Ape: " << (apellido ? apellido : "Sin apellido") << endl << "FecNac: " << this->fnac;
}

/** OPERADORES */

Persona & Persona :: operator = (const Persona &obj)
{
    this->dni = obj.dni;
    this->sexo = obj.sexo;
    strcpy(this->nombre, obj.nombre);
    delete []this->apellido; //Eliminamos el contenido de apellido
    this->apellido = duplicaCadena(obj.apellido);
    if (!this->apellido && obj.apellido && *obj.apellido)
        cerr << "Sin memoria en operador =" << endl;
    this->fnac = obj.fnac;

    return *this;
}

ostream & operator << (ostream &salida, const Persona &per)
{
    salida << "DNI: " << per.dni << endl << "Sexo: " << per.sexo << endl << "Nom: " << (*per.nombre ? per.nombre : "Sin nombre") << endl << "Ape: " << (per.apellido ? per.apellido : "Sin apellido") << endl << "FecNac: " << per.fnac;
    return salida;
}

istream & operator >>(istream &entrada, Persona &per)
{

    cout << "Ingrese el DNI: ";
    entrada >> per.dni;
    cout << "Ingrese el sexo: ";
    entrada >> per.sexo;

    char nom[20];
    cout << "Ingrese el nombre: ";
    fflush(stdin); //Limpiamos el buffer de memoria
    entrada.getline(nom, sizeof(nom), '\n'); //Toma solo hasta el enter
    strcpy(per.nombre, nom);

    char ape[500];
    cout << "Ingrese el apellido: ";
    fflush(stdin);
    entrada.getline(ape, sizeof(nom), '\n');
    per.apellido = duplicaCadena(ape);
    if (!per.apellido && *ape)
        cerr << "Sin memoria en operador >>";

    cout << "Ingrese la fecha de nac: ";
    entrada >> per.fnac;
    return entrada;
}
