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
    ListaDeEstudiantes *list = (Estudiante *)malloc(sizeof(ListaDeEstudiantes));
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
    ListaDeMaterias *list = (Materia *)malloc(sizeof(ListaDeMaterias));
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
    if (node == NULL)
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
    NodoEstudiante *node = NewNodoEstudiante(entrada);
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
    NodoEstudiante *ingreso = NewNodoEstudiante(entrada);
    NodoEstudiante *cursor = NewNodoEstudiante(list->head);

    while (cursor != NULL)
    {
        if (entrada->edad > cursor->datos->edad)
        {
            ingreso->next = cursor->next;
            cursor->next = ingreso;
            return;
        }
        else
        {
            cursor = cursor->next;
        }
    }
}

void eliminarEstudiante(ListaDeEstudiantes* list,Estudiante* estudiante){
    
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
        if (getEdadDelEstudiante(GetEstudiante(cursor)) == edad)
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
        if (getEdadDelEstudiante(GetEstudiante(cursor)) == edad)
        {
            printf("Estudiante:%s \n", getNombreDelEstudiante(GetEstudiante(cursor)));
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

/*
Metodos:

Agregar Elemento
entre medio

Eliminar Elemento
Al Principio, al final, entre medio

Get Dato

Find Dato
*/