#include <stdio.h>
#include "structs/ListaStructs/Lista.h"

int main() {

    Lista* mi_lista = NewLista();
    Estudiante *nacho = NewEstudiante("Ignacio",20);
    Estudiante *agus = NewEstudiante("Agustin",25);
    

    printf(*nacho->nombre);
    printf(nacho->edad);
    
    printf(*agus->nombre);
    printf(agus->edad);
    

    return 0;
}