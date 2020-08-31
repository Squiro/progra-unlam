#ifndef COLA_H
#define COLA_H

#include <tipos.h>

#ifndef NODO_LISTA_SIMPLE
#define NODO_LISTA_SIMPLE
typedef struct s_nodo
{
	t_info_cola info; /** El tipo definido en tipos.h **/
	struct s_nodo* psig;
}t_nodo;
#endif // COLA_H

typedef t_nodo* t_cola;

void crear_cola(t_cola* pc);
int poner_en_cola(t_cola* pc, const t_info_cola* pd);
int sacar_de_cola(t_cola* pc, t_info_cola* pd);
int frente_de_cola(const t_cola* pc, t_info_cola* pd);
int cola_vacia(const t_cola* pc);
int cola_llena(const t_cola* pc);
void vaciar_cola(t_cola* pc);

void crear_cola_res(t_cola* pc);
int poner_en_cola_res(t_cola* pc, const t_info_cola* pd);
int sacar_de_cola_res(t_cola* pc, t_info_cola* pd);
int frente_de_cola_res(const t_cola* pc, t_info_cola* pd);
int cola_vacia_res(const t_cola* pc);
int cola_llena_res(const t_cola* pc);
void vaciar_cola_res(t_cola* pc);


#endif // COLA_H
