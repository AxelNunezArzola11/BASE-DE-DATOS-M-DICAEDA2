#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define TAM_HASH 10
#define MAX 100
#include "nodo.h"

int hash(char *key);
void acomodar(Paciente p, int llave);
void buscarPaciente();
Nodo *buscandoPaciente(char *nombre, int llave);
void busquedaBinaria();
int buscandoPacienteBinario(char arreglo[][MAX],char *nombre, int size);
void eliminarPaciente();
void eliminandoPaciente(Nodo *resultado, int llave);
void mostrarPaciente(Paciente p);
void mostrarTodo();
void QuickSort(int llave);
void quicksort(char arreglo[][MAX], int izquierda, int derecha);
int particion(char arreglo[][MAX], int izquierda, int derecha);
void intercambiar(char *a, char *b);
void create_json(char* file_name );

#endif // LISTA_H_INCLUDED
