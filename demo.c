#include <stdio.h>
#include "structs/ListaStructs/Lista.h"

int main() {

    Lista* mi_lista = NewLista();
   // Estudiante *nacho = NewEstudiante("Ignacio",20);
    Estudiante *agus = NewEstudiante("Agustin",25);
    char nombre[10];
    int edad;
    printf("Prueba\n");
    printf("Ingrese nombre y edad del estudiante a registrar:");
    scanf("%s %d", nombre, &edad );
    Estudiante *alumno = NewEstudiante(nombre, edad);
    printf("Estudiante %s registrado correctamente \n",alumno->nombre );
    inserInicio(mi_lista,alumno);
    printf("Cantidad de alumnos: %d \n",mi_lista->size );
    
    printf("%s \n",agus->nombre );
    printf("%d \n",agus->edad );
    

    return 0;
}