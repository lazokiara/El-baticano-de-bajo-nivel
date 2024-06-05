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

    printf("\n\n");

    Estudiante *kiara = NewEstudiante("Kiara",30);

    inserInicio(mi_lista,nacho);
    inserInicio(mi_lista,agus);
    inserFinal(mi_lista,kiara);

    Estudiante* prueba = getEstudiantePorEdad(mi_lista,20);

    printf("%s", prueba->nombre);

    // Nodo* cursor = mi_lista->head;
    // while (cursor!= NULL)
    // {
    //     /* code */
    // }
     

    printf("el estudiante prueba %s \n", mi_lista->head->datos->nombre);
    printf("su edad es: %d \n", mi_lista->head->datos->edad);
    
    printf("el estudiante prueba %s \n", mi_lista->tail->datos->nombre);
    printf("su edad es: %d \n", mi_lista->tail->datos->edad);
    
   
    

    return 0;
}