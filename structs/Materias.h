#include <stdlib.h>
struct ListaDeEstudiantes;

typedef struct structMateria{
    char *nombre;
    int id_materia;
    struct structMateria *correlativas;
    struct structMateria *prox;
    struct structListaDeEstudiantes *alumnos;
}Materia;

Materia *NewMateria(char *nom, int id){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->id_materia = id;
    materia->nombre = nom;
    materia-> prox = NULL;
    return materia;
}
