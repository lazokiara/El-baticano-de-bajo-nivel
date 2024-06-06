
#include "../alumno.h"
#include "../Materias.h"


typedef struct structNodoEstudiante {
    Estudiante *datos;
    struct structNodoEstudiante *next;
} NodoEstudiante;

typedef struct structNodoMateria {
    Materia *datos;
    struct structNodoMateria *next;

} NodoMateria;

NodoEstudiante *NewNodoEstudiante(Estudiante *estudiante) {
    NodoEstudiante *node;
    node = (NodoEstudiante*)malloc(sizeof(NodoEstudiante));
    node->datos= estudiante;
    node->next = NULL;
    return node;
}

Estudiante *GetEstudiante(NodoEstudiante *node){
    return node->datos;
}
NodoMateria *NewNodoMateria(Materia *materia) {
    NodoMateria *node;
    node = (NodoMateria*)malloc(sizeof(NodoMateria));
    node->datos= materia;
    node->next = NULL;
    return node;
}
Materia *GetMateria(NodoMateria *node){
    return node->datos;
}