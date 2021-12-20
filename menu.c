#include <stdio.h>
/**    
Este es el archivo menu, en este despliega un menu que muestra las opciones, en total son 7 
la función leerOpcion lee el numero escogido del usuario
*/
void menu() {
    printf("\n\n");
    printf("\tBASE DE DATOS\n");
    printf("(0) Terminar\n");
    printf("(1) Agregar un paciente\n");
    printf("(2) Buscar un paciente\n");
    printf("(3) Borrar un paciente\n");
    printf("(4) Mostrar todos los pacientes\n");
    printf("(5) Mostrar una llave en orden alfab%ctico\n",130);
    printf("(6) Buscar paciente por busqueda binaria\n");
    printf("(7) Crear archivo en json\n");

}

int leerOpcion() {
    int respuesta;
    do {
        menu();
        printf("\nCual es tu eleccion? ");
        scanf("%d",&respuesta);
        if (respuesta<0 || respuesta>7) {
            printf("Hay un error en tu eleccion!\n");
            printf("Valores solo entre 0 y 7 por favor\n");
        }
    } while(respuesta<0 || respuesta>7);
    printf("\n");
    return respuesta;

}
