#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tabla_hash.h"
#define FILE_HANDLER json_output
#define FILE_HANDLER1 stderr
//Nodo *TablaHash[] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
Nodo *TablaHash[TAM_HASH] = {};
/*************************************************************************************************/
/**
 @brief convierte el nombre en un entero que no sea mayor al tamaño de la hash table
@param un apuntador de tipo hash
@returns devuelve un entero
  */
int hash(char *key){
    int longitud = strlen(key);
    int suma = 0,i;
    for(i=0;i<longitud;i++){
        suma+= key[i];
    }
    return suma % TAM_HASH;
}
/*************************************************************************************************/
/**
 @brief acomoda el paciente en la tabla hash
@param una variable de tipo paciente y una llave de tipo int
@returns no devuelve nada
  */
void acomodar(Paciente p, int llave){
    Nodo *nuevo = crearNodo();
    nuevo->informacion = p;
    nuevo->anterior = NULL;
    nuevo->siguiente = TablaHash[llave];
    if(TablaHash[llave]) TablaHash[llave]->anterior = nuevo;
    TablaHash[llave] = nuevo;
}
/*************************************************************************************************/
/**
 @brief bsuca un paciente lee el nombre desde la consola
@param ningun parametro
@returns no devuelve nada
  */
void buscarPaciente(){
    char nombre[100];
    fflush(stdin);
    printf("Ingresa el nombre del paciente a buscar: ");
    scanf("%s",nombre);
    int llave = hash(nombre);
    printf("Llave %d: %s\n\n",llave,nombre);
    Nodo *aux = buscandoPaciente(nombre, llave);
    if(aux){
        mostrarPaciente(aux->informacion);
    }
    else{
        printf("El paciente que busca no est%c registrado\n",160);
    }
}
/*************************************************************************************************/
/**
 @brief Busca un paciente con la llave y nombte
@param un apuntador de tipo char un entero la llave
@returns devuelve un nodo
  */
Nodo *buscandoPaciente(char *nombre, int llave){
    Nodo *p = TablaHash[llave];
    while(p){
        if(strcmp(p->informacion.nombre, nombre) == 0){
            return p;
        }
        p = p->siguiente;
    }
    return NULL;
}
/*************************************************************************************************/
/**
 @brief realiza busqueda binaria
@param sin parametro
@returns no devuelve nada
  */
void busquedaBinaria(){
    int longitud = 0, cont = 0;
    char nombre[100];
    fflush(stdin);
    printf("Ingresa el nombre del paciente a buscar: ");
    scanf("%s",nombre);
    int llave = hash(nombre);
    printf("Llave %d: %s\n\n",llave,nombre);
    Nodo *aux = TablaHash[llave];
    if(aux == NULL){
        printf("El paciente que busca no est%c registrado\n",160);
    }
    else{
        while(aux != NULL){
            longitud++;
            aux = aux->siguiente;
        }
        char arreglo[longitud][MAX];
        aux = TablaHash[llave];
        while(aux != NULL){
            memcpy(arreglo[cont], aux->informacion.nombre, MAX);
            cont++;
            aux = aux->siguiente;
        }
        quicksort(arreglo, 0, longitud - 1);
        if(buscandoPacienteBinario(arreglo,nombre,longitud) == 1){
            aux = buscandoPaciente(nombre, llave);
            mostrarPaciente(aux->informacion);
        }
        else{
            printf("El paciente que busca no est%c registrado\n",160);
        }
    }
}
/*************************************************************************************************/
/**
 @brief realiza una busqueda binaria
@param un apuntador de tipo char,entero size y un arreglo
@returns devuelve un entero
  */
int buscandoPacienteBinario(char arreglo[][MAX],char *nombre, int size){
    int izq = 0;
    int der = size - 1;
    while(izq <= der){
        int medio = (der + izq) / 2;
        if(strcmp(nombre, arreglo[medio] ) == 0){
            return 1;
        }
        if(strcmp(nombre, arreglo[medio]) < 0){
            der = medio - 1;
        }
        if(strcmp(nombre, arreglo[medio]) > 0){
            izq = medio + 1;
        }
    }
    return -1;
}
/*************************************************************************************************/
/**
 @brief elimina un paciente, esta funcion lee el paciente
  */
void eliminarPaciente(){
    char nombre[100];
    fflush(stdin);
    printf("Ingresa el nombre del paciente a eliminar: ");
    scanf("%s",nombre);
    int llave = hash(nombre);
    printf("Llave %d: %s\n\n",llave,nombre);
    Nodo *aux = buscandoPaciente(nombre, llave);
    if(aux){
        mostrarPaciente(aux->informacion);
        eliminandoPaciente(aux,llave);
    }
    else{
        printf("El paciente que busca no est%c registrado\n",160);
    }
}
/*************************************************************************************************/
/**
 @brief Elimina el paciente de la tabla hash
@param un apuntador de tipo Nodo resultado
@returns devuelve un entero llave
  */
void eliminandoPaciente(Nodo *resultado, int llave){
    if(resultado->siguiente){
        resultado->siguiente->anterior = resultado->anterior;
    }
    if(resultado->anterior){
        resultado->anterior->siguiente = resultado->siguiente;
    }
    else{
        TablaHash[llave] = resultado->siguiente;
    }
    free(resultado);
    printf("\nEl Paciente ha sido eliminado del registro\n\n");
}

void mostrarTodo(){
    Nodo *aux;
    int i,cont=0;
    for(i=0;i<TAM_HASH;i++){
        aux = TablaHash[i];
        if(aux!=NULL){
            printf("Pacientes de la llave %d:\n",i);
        }
        while(aux != NULL){
            mostrarPaciente(aux->informacion);
            printf("\n\n");
            cont++;
            aux = aux->siguiente;
        }
    }
    if(cont == 0){
        printf("No hay ning%cn paciente registrado a%cn\n",163,163);
    }
}

void mostrarPaciente(Paciente p){
    printf("Nombre del paciente: %s\n",p.nombre);
    printf("Fecha del registro: %d\n",p.fecha);
    printf("Hora de registro: %s\n",p.hora);
    printf("Edad del Paciente: %d\n",p.edad);
    printf("Diagn%cstico del paciente:\n%s\n",162,p.diagnostico);
}

void QuickSort(int llave){
    int longitud = 0,cont = 0,i;
    Nodo *aux = TablaHash[llave];
    if(aux == NULL){
        printf("No hay ning%cn paciente registrado con esa llave\n",163);
    }
    else{
        while(aux != NULL){
            longitud++;
            aux = aux->siguiente;
        }
        char arreglo[longitud][MAX];
        aux = TablaHash[llave];
        while(aux != NULL){
            memcpy(arreglo[cont], aux->informacion.nombre, MAX);
            cont++;
            aux = aux->siguiente;
        }
        quicksort(arreglo, 0, longitud - 1);
        for(i=0;i < longitud; i++){
            aux = TablaHash[llave];
            do{
                if(strcmp(arreglo[i],aux->informacion.nombre) == 0){
                    mostrarPaciente(aux->informacion);
                    printf("\n");
                    break;
                }
                aux = aux->siguiente;
            }while(aux != NULL);
        }
    }
}

void quicksort(char arreglo[][MAX], int izquierda, int derecha) {
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}

int particion(char arreglo[][MAX], int izquierda, int derecha) {
  char pivote[MAX];
  char temporal[MAX];
  memcpy(pivote,arreglo[izquierda],MAX);
  while (1) {
    while (strcmp(arreglo[izquierda], pivote) < 0) {
      izquierda++;
    }
    while (strcmp(arreglo[derecha], pivote) > 0) {
      derecha--;
    }
    if (izquierda >= derecha) {
      return derecha;
    } else {

      memcpy(temporal,arreglo[izquierda],MAX);
      memcpy(arreglo[izquierda],arreglo[derecha],MAX);
      memcpy(arreglo[derecha],temporal,MAX);

      izquierda++;
      derecha--;
    }
  }
}

void intercambiar(char *a, char *b) {
  char temporal = *a;
  *a = *b;
  *b = temporal;
}
void create_json(char* file_name ){//pasar com argumento la tabla hash
FILE* json_output=fopen(file_name, "w" );
if( !json_output )
   {
      //printf( stderr,"Error abriendo el archivo\n" );
      exit( 1 );
   }
   fprintf( FILE_HANDLER, "{\n" );
   fprintf( FILE_HANDLER, "\"Paciente\": [\n" );
   for( size_t i = 0; i < TAM_HASH; ++i )//recorre la tabla hash
   {
     if(TablaHash[i]->informacion.nombre!=NULL){
   if( i > 0 ) fprintf( FILE_HANDLER, ",\n" );
   fprintf( FILE_HANDLER, "{ " );
   fprintf( FILE_HANDLER,"\"nombre\": \"%s\", \"fecha\": %d, \"hora\": \"%s\", \"edad\": %d,\"diagnostico\": \"%s\"",
   TablaHash[i]->informacion.nombre,TablaHash[i]->informacion.fecha,TablaHash[i]->informacion.hora,
   TablaHash[i]->informacion.edad,TablaHash[i]->informacion.diagnostico);
   fprintf( FILE_HANDLER, " }" );
    }
   else{ //si no hay informacion que guarde valores vacíos en los strings y enteros en 0
   if( i > 0 ) fprintf( FILE_HANDLER, ",\n" );
   fprintf( FILE_HANDLER, "{ " );
   fprintf( FILE_HANDLER,"\"nombre\": \"\", \"fecha\":0, \"hora\": \"\", \"edad\":0,\"diagnostico\": \"\"");
   fprintf( FILE_HANDLER, " }" );
   continue;
   }
   }
   fprintf( FILE_HANDLER, "\n]" );
      fprintf( FILE_HANDLER, "\n}" );
  fclose( json_output );	
}
