#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

#define MAX_CADENA 999

typedef struct{
    //int clave_registro;
    char nombre [100];
    int fecha;
    char hora [10];
    int edad;
    char diagnostico [MAX_CADENA];
}Paciente;

void leer();

#endif // PACIENTE_H_INCLUDED
