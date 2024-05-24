#include <stdio.h>
#include "structs/ListaStructs/Lista.h"

int main() {

    Lista* mi_lista = NewLista();
    Estudiante *nacho = NewEstudiante("Ignacio",20);
    Estudiante *agus = NewEstudiante("Agustin",25);
    
    printf("Prueba\n");

    printf("%s \n",nacho->nombre );
    printf("%d \n",nacho->edad );
    
    printf("%s \n",agus->nombre );
    printf("%d \n",agus->edad );
    

    return 0;
}