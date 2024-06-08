#include "Nodo.h"
#include <stdlib.h> // Incluimos stdlib.h para malloc

typedef struct structListaDeEstudiantes
{
    NodoEstudiante *head;
    NodoEstudiante *tail;
    int size;
} ListaDeEstudiantes;

typedef struct structListaDeMaterias
{
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaDeMaterias;


ListaDeEstudiantes *NewListaDeEstudiante()
{
    ListaDeEstudiantes *list = (Estudiante*)malloc(sizeof(ListaDeEstudiantes));
    // if (list == NULL) {
    //     return NULL; // Manejo de error si malloc falla
    // }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
ListaDeMaterias *NewListaDeMaterias()
{
    ListaDeMaterias *list = (Materia*)malloc(sizeof(ListaDeMaterias));
    // if (list == NULL) {
    //     return NULL; // Manejo de error si malloc falla
    // }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOf(ListaDeEstudiantes *list)
{
    return list->size;
}

/// @brief Inserta un estudiante a la cabeza de la lista
/// @param list
/// @param entrada
void inserInicio(ListaDeEstudiantes *list, Estudiante *entrada)
{
    NodoEstudiante *node = NewNodoEstudiante(entrada);
    if (node->datos == NULL)
    {
        return;
    }
    if (SizeOf(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

/// @brief Inserta un estudiante a la cola de la lista
/// @param list
/// @param entrada
void inserFinal(ListaDeEstudiantes *list, Estudiante *entrada)
{
    NodoEstudiante* node = NewNodoEstudiante(entrada);
    if (node->datos == NULL)
    {
        return; 
    }
    if (SizeOf(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

/// @brief Inserta un elemento de forma ordenada. Es O(n) pero con mejoras que lo pueden agilizar
/// @param list 
/// @param entrada 
void insertarOrdenadamente(ListaDeEstudiantes *list, Estudiante *entrada)
{
    if (SizeOf(list) < 1 || list->head->datos->edad > entrada->edad)
    {
        inserInicio(list, entrada);
        return;
    }
    else if (list->tail->datos->edad < entrada->edad)
    {
        inserFinal(list, entrada);
        return;
    }

    //Nodo a ingresar apunta al head
    NodoEstudiante *ingreso = NewNodoEstudiante(entrada);
    ingreso->next = list->head;
    //NodoEstudiante *cursor = NewNodoEstudiante(list->head);

    while (ingreso->next->next != NULL)
    {
        if (getEdad(GetEstudiante(ingreso->next->next)) >= getEdad(GetEstudiante(ingreso)))
        {
            //Creo que es IMPOSIBLE :O
            // ingreso->next->next= ingreso->next;
            // ingreso->next = ingreso
            return;
        }
        else
        {
            //Iteramos sobre la lista
            ingreso->next = ingreso->next->next;
        }
    }
}

void eliminarEstudiante(ListaDeEstudiantes* list,Estudiante* estudiante){
    NodoEstudiante *actual = list->head;
    NodoEstudiante *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || actual->datos->edad != estudiante->edad)) {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL) {
        if (list->head) {
            printf("Lista vacia \n");
        } else {
            printf("No se encontro el elemento en la lista \n");
        }
    } else {
        if (list->head == actual) {
            list->head = actual->next;
        } else {
            anterior->next = actual->next;
        }
        
        free(actual);
    }
    
}

// Sin Usar
/// @param list
/// @param edad
/// @return Devuelve el primer estudiante que se encuentra en la lista a partir de una edad
Estudiante *getEstudiantePorEdad(ListaDeEstudiantes *list, int edad)
{
    NodoEstudiante *cursor = list->head;
    while (cursor != NULL)
    {
        if (getEdad(GetEstudiante(cursor)) == edad)
        {
            return GetEstudiante(cursor);
        }
        cursor = cursor->next;
    }
    return NULL;
}
Estudiante *getEstudiantePorNombre(ListaDeEstudiantes *list, char nombre)
{
    NodoEstudiante *cursor = list->head;
    while (cursor != NULL)
    {
        if (getNombre(GetEstudiante(cursor)) == nombre)
        {
            return GetEstudiante(cursor);
        }
        cursor = cursor->next;
    }
    return NULL;
}

/// @brief Imprime todos los estudiantes que tengan la edad ingresada
/// @param list
/// @param edad
void imprimirEstudiantesPorEdad(ListaDeEstudiantes *list, int edad)
{
    NodoEstudiante *cursor = list->head;
    if (cursor == NULL)
    {
        printf("El sistema no tiene estudiantes.\n");
    }
    while (cursor != NULL)
    {
        if (getEdad(GetEstudiante(cursor)) == edad)
        {
            printf("Estudiante:%s %s\n", getNombre(GetEstudiante(cursor)), getApellido(GetEstudiante(cursor)));
        }
        cursor = cursor->next;
    }
}

/// @brief Inserta un estudiante a la cola de la lista
/// @param list
/// @param entrada
void addMateria(ListaDeMaterias *list, Materia *materia)
{
    NodoMateria *node = NewNodoMateria(materia);
    if (node == NULL)
    {
        return; // Manejo de error si NewNodo falla
    }
    if (SizeOf(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

 void enlistarAlumnoEnMateria(Materia *materia, Estudiante *estudiante){
     insertarOrdenadamente(materia->alumnos, estudiante);
 }
 