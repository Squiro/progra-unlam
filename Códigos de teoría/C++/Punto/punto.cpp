#include "punto.h"

/** /!\ En sobrecarga, la diferencia se basa pura y exclusivamente en la cantidad de parametros. No en el tipo de dato que
        devuelven, ni otras cosas así.

    SOBRE MEMORIA ESTATICA:

    En memoria estática, no es necesario hacer el constructor por copia. C++ lo hace directamente.
    Utilizarlo cuando pidan hacer lo mínimo indispensable en un parcial.
    Lo mismo sucede con algunos operadores. C++ lo maneja por su cuenta.

    Pero si tenemos memoria dinámica, es necesario sobrecargar los operadores.

    SOBRE THIS:
    this es un puntero al mismo objeto. Si quiero el contenido, uso *this

    SOBRE REFERENCE PASS &obj:
    A esto se le llama pasaje por referencia. Es algo totalmente diferente al pasaje por copia de C. Lo que hace es "pasar"
    el objeto, y asignarle un nombre que usamos como referencia para llamarlo.

    SOBRE OPERATORS:
    El que está antes del signo es el dueño del operador

    p4 = p3 + 2; -> usa el op de los objetos puntos
    p5 = 2 + p3; -> usa el op de los enteros

*/

//El orden es: tipo de retorno, nombre de clase, op de ambito


//Constructor por defecto.
//Primero se escribe lo que se devuelve, pero los constructores no devuelven nada.
//Por eso va vacío.
// :: -> Operador de ambito
//Después va el nombre del constructor.

/*Punto :: Punto()
{
    this->x = 0; //x = 0;
    this->y = 0; //y = 0;
}*/

// /!\ Esto es un inicializador. Es necesario para inicializar atributos estaticos.
/*Punto :: Punto():x(0),y(0)
{
    //El inicializador no lleva NADA adentro.
}*/

//Sirve para parametrizado por defecto y parametrizado normal
Punto :: Punto(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

Punto :: Punto(const int x)
{
    this->x = x;
}

//Por copia
Punto :: Punto(const Punto &obj)
{
    this->x = obj.x;
    this->y = obj.y;
}

//Inicializador por copia
/*Punto :: Punto(const Punto &obj):x(obj.x),y(obj.y)
{

}*/

void Punto :: mostrar()
{
    cout << "(" << this->x << "," << this->y << ")" << endl;
}

void Punto :: mostrarMultiplicado(int num)
{
    cout << "(" << this->x*num << "," << this->y*num << ")" << endl;
}

//Operador =
Punto &Punto :: operator = (const Punto &obj)
{
    this->x = obj.x;
    this->y = obj.y;

    return *this; //Retornamos el objeto llamador modificado
}

//Operador +=
Punto &Punto :: operator += (const Punto &obj)
{
    this->x += obj.x;
    this->y += obj.y;

    return *this;
}

//Operador -=
Punto &Punto :: operator -= (const Punto &obj)
{
    this->x -= obj.x;
    this->y -= obj.y;

    return *this;
}

//Operador +
//Uno se pasa por parametro, el otro esta implicito. El que esta implicito es el llamador.
//e.g. = p1 + p2 => p1 = llamador, p2 llamado
Punto Punto :: operator + (const Punto &obj)const
{
    //Se puede simplificar todavía más (le gusta a Lopez)
    return Punto(obj.x + x, obj.y + y);

    /*Se puede simplificar si lo hacemos por copia
    Punto aux(obj);
    //Punto(*this) al ser this un puntero, necesito acceder al contenido del puntero, que es el objeto

    aux.x += this->x;
    aux.y += this->y;

    return aux;*/

    /*Punto aux;

    aux.x = obj.x + this->x;
    aux.y = obj.y + this->y;

    return aux;*/
}

Punto Punto :: operator - (const Punto &obj)const
{
    //Se puede simplificar todavía más (le gusta a Lopez)
    return Punto(obj.x - x, obj.y - y);
}

Punto Punto :: operator - (const int num)const
{
    return Punto(x - num, y - num);
}

Punto Punto :: operator + (const int num)const
{
    return Punto(x + num, y + num);
}

//Como el operador es de int, no me pertenece, y no me puedo adueñar
//No debo poner el friend aca, solo en el .h
Punto operator + (const int num, const Punto &obj)
{
    return Punto(obj.x + num, obj.y + num);
}

//Pre fix ++, primero incrementar, desp asignar
//Notar que tiene un ampersand
Punto & Punto :: operator ++()
{
    this->x++;
    this->y++;

    return *this;
}

//Pos fix ++, primero asigna, desp incrementa
Punto Punto :: operator ++(int)
{
    Punto aux(*this);
    x++; //Incremento
    y++; //Incremento

    return aux; //Devuelvo el aux sin incremento
}

bool Punto :: operator == (const Punto & obj)const
{
    return this->x == obj.x && this->y == obj.y;

    /*if (this->x == obj.x && this->y == obj.y)
        return true;
    return false;*/
}

//Los operadores de mayor y menor en objetos depende mucho de si realmente tienen sentido o no hacerlos
bool Punto :: operator > (const Punto & obj)const
{
    return sqrt(pow(x, 2)+pow(y,2)) > sqrt(pow(obj.x,2)+pow(obj.y,2));
}

//Get y Sets
int Punto :: getX()
{
    return this->x;
}

int Punto :: getY()
{
    return this->y;
}

void Punto :: setX(int x)
{
    this->x = x;
}

void Punto :: setY(int y)
{
    this->y = y;
}
