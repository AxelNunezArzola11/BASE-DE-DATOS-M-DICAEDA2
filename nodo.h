#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "paciente.h"



struct nodo {
    Paciente informacion;
    struct nodo *siguiente, *anterior;
};

typedef struct nodo Nodo;

Nodo *crearNodo();

#endif // NODO_H_INCLUDED
