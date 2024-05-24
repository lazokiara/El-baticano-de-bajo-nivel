#include <stdlib.h>

typedef struct structEstudiante {
     char *nombre;
    int edad;

} Estudiante;

Estudiante *NewEstudiante(char *nom, int ed) {
    Estudiante *estudiante;
    malloc(sizeof(Estudiante));
    estudiante->edad = ed;
    estudiante->nombre = nom;
    return estudiante;
}