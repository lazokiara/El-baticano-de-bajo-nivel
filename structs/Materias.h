#include <stdlib.h>
//#include "ListaStructs/Lista.h"

typedef struct Materia{
    char *nombre;
    int id_materia;
   // Lista *alumnos;
    Materia *correlativas;
}Materia;

Materia *NewMateria(char *nom, int id){
    Materia *materia;
    materia = malloc(sizeof(Materia));
    materia->id_materia = id;
    materia->nombre = nom;
    return materia;
}