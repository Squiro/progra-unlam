#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define TAM_PILA 100

typedef struct {
    int pila[TAM_PILA];
    int tope;
}t_pila;

void crear_pila(t_pila *);
int apilar(t_pila *, int valor);
int pila_vacia(const t_pila *);
int pila_llena(const t_pila *);
int desapilar(t_pila *, int* valor);
int ver_tope(const t_pila *, int* valor);
void vaciar_pila(t_pila *);


#endif // PILA_H_INCLUDED
