#include "producto.h"
#include "bulto.h"

Producto :: Producto (const char * desc, const int alto, const int ancho, const int largo)
{
    if (desc)
    {
        strncpy(this->desc, desc, sizeof(this->desc)-1);
        this->desc[sizeof(this->desc)] = '\0';
    }
    else
        *this->desc = '\0';

    this->alto = alto;
    this->ancho = ancho;
    this->largo = largo;
}

//int Producto :: volumen() const -> read-only
int Producto :: volumen()
{
    return this->alto * this->ancho * this->largo;
}

char * Producto :: getDesc()
{
    return this->desc;
}

Bulto Producto :: operator + (Producto &prod)
{
    return Bulto(Bulto::concatenar(this->desc, prod.desc), this->volumen() + prod.volumen());
}
