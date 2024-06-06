#include <stdlib.h>
//#include "Lista.h"

typedef struct structMateria{
    char *nombre;
    int id_materia;
    struct structMateria *correlativas;
    struct structMateria *prox;
   // ListaDeEstudiantes *alumnos; no funciona import
}Materia;

Materia *NewMateria(char *nom, int id){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->id_materia = id;
    materia->nombre = nom;
    materia-> prox = NULL;
    return materia;
}
