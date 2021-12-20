#include <stdlib.h>
#include <string.h>

#include "nodo.h"

/**    
crea una estructura de tipo nodo, que incluye un campo de tipo paciente
*/

Nodo *crearNodo() {
    Nodo *pNodo;
    pNodo = malloc(sizeof(Nodo));
    return pNodo;
}
