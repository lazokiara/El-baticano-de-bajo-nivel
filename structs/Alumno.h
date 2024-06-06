#include <stdlib.h>

typedef struct structEstudiante {
    char *nombre;
    int edad;

} Estudiante;

Estudiante *NewEstudiante(char *nom, int ed) {
    Estudiante *estudiante;
    estudiante = (Estudiante*)malloc(sizeof(Estudiante));
     if (estudiante == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    strcpy(estudiante->nombre, nom);
    estudiante->edad = ed;
    //estudiante->nombre = nom;
    return estudiante;
}

int getEdadDelEstudiante(Estudiante* alumn) {
    return alumn->edad;
}

char* getNombreDelEstudiante(Estudiante* alumn) {
    return alumn->nombre;
}