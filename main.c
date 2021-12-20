#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "paciente.h"
#include "tabla_hash.h"
/**    
Este es el archivo main, en este despliega un menu que muestra las opciones,
posteriormente el usuario teclea una opción 
*/
int main()
{
    int opcion, llave;
    do{
        opcion = leerOpcion();
        switch(opcion){
            case 1:{
                leer();
                break;
            }
            case 2:{
                buscarPaciente();
                break;
            }
            case 3:{
                eliminarPaciente();
                break;
            }
            case 4:{
                mostrarTodo();
                break;
            }
            case 5:{
                do{
                    printf("Ingrese la llave de la tabla hash para mostrar en orden: ");
                    scanf("%d",&llave);
                    if(llave < 0 || llave > 9){
                        printf("Hay un error en tu eleccion!\n");
                        printf("Valores solo entre 0 y 9 por favor\n");
                    }
                }while(llave < 0 || llave > 9);
                printf("\n");
                QuickSort(llave);
                break;
            }
            case 6:{
                busquedaBinaria();
                break;
            }
            case 7:{
            	char archivojson[20]="g03.json";
				create_json(archivojson);
				break;
			}
            case 0:{
                printf("Hasta luego\n");
                break;
            }
            default: printf("Opcion no reconocida\n");
            break;
        }
    }while(opcion!=0);
    return 0;
}
