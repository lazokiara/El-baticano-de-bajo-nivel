
#include "../alumno.h"
#include "../Materias.h"

// ------------------------- Nodo Estudiante ------------------------- //

typedef struct structNodoEstudiante
{
    Estudiante *datos;
    struct structNodoEstudiante *next;
} NodoEstudiante;

NodoEstudiante *NewNodoEstudiante(Estudiante *estudiante)
{
    NodoEstudiante *node;
    node = (NodoEstudiante *)malloc(sizeof(NodoEstudiante));
    node->datos = estudiante;
    node->next = NULL;
    return node;
}

Estudiante *GetEstudiante(NodoEstudiante *node)
{
    return node->datos;
}
// ------------------------- Nodo Materias ------------------------- //
typedef struct structNodoMateria
{
    Materia *datos;
    struct structNodoMateria *next;

} NodoMateria;

NodoMateria *NewNodoMateria(Materia *materia)
{
    NodoMateria *node;
    node = (NodoMateria *)malloc(sizeof(NodoMateria));
    node->datos = materia;
    node->next = NULL;
    return node;
}

Materia *GetMateria(NodoMateria *node)
{
    return node->datos;
}