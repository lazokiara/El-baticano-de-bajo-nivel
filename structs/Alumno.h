#include <stdlib.h>

typedef struct structEstudiante {
    char *nombre;
    int edad;

} Estudiante;

Estudiante *NewEstudiante(char *nom, int ed) {
    Estudiante *estudiante;
    estudiante = malloc(sizeof(Estudiante));
    estudiante->edad = ed;
    estudiante->nombre = nom;
    return estudiante;
}

int getEdadDelEstudiante(Estudiante* alumn) {
    return alumn->edad;
}

char* getNombreDelEstudiante(Estudiante* alumn) {
    return alumn->nombre;
}