#include <string.h>
#include <stdio.h>
#include "paciente.h"
#include "tabla_hash.h"
/**    
Funíon que lee los datos de tipo paciente
posteriormente llama a la función hash
y acomda el paciente
*/

void leer()
{
    
    
    Paciente p;
    fflush(stdin);
    printf("Inserte nombre del paciente, solo un nombre: ");
    scanf("%s",p.nombre);
    fflush(stdin);
    printf("Fecha de registro solamente enteros?: ");
    scanf("%d",&p.fecha);
    printf("Hora de registro?: ");
    scanf("%s",p.hora);
    fflush(stdin);
    printf("Edad?: ");
    scanf("%d",&(p.edad));
    fflush(stdin);
    printf("Diagn%cstico del paciente: ",162);
    scanf("%s",p.diagnostico);
    int llave = hash(p.nombre);
    printf("Llave %d: %s",llave, p.nombre);
    acomodar(p, llave); 
}
