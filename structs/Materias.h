#include <stdlib.h>
//#include "ListaStructs/Lista.h"

typedef struct structMateria{
    char *nombre;
    int id_materia;
    struct structMateria *correlativas;
    struct structMateria *prox;
}Materia;

Materia *NewMateria(char *nom, int id){
    Materia *materia;
    materia = malloc(sizeof(Materia));
    materia->id_materia = id;
    materia->nombre = nom;
    materia-> prox = NULL;
    return materia;
}
