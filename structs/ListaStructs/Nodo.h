
#include "../alumno.h"

typedef struct structNodo {
    Estudiante *datos;
    struct structNodo *next;
} Nodo;

Nodo *NewNodo(Estudiante *estudiante) {
    Nodo *node;
    malloc(sizeof(Nodo));
    node->datos= estudiante;
    node->next = NULL;
    return node;
}
/*
Crear Nodo


*/