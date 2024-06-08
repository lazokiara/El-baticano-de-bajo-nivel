#include "Nodo.h"
#include <stdlib.h>

// --------------------------------------------------- Lista Estudiante --------------------------------------------------- //

typedef struct structListaDeEstudiantes
{
    NodoEstudiante *head;
    NodoEstudiante *tail;
    int size;
} ListaDeEstudiantes;

ListaDeEstudiantes *NewListaDeEstudiante()
{
    ListaDeEstudiantes *list = (Estudiante *)malloc(sizeof(ListaDeEstudiantes));

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

    // Nodo a ingresar apunta al head
    NodoEstudiante *ingreso = NewNodoEstudiante(entrada);
    ingreso->next = list->head;
    // NodoEstudiante *cursor = NewNodoEstudiante(list->head);

    while (ingreso->next->next != NULL)
    {
        if (getEdad(GetEstudiante(ingreso->next->next)) >= getEdad(GetEstudiante(ingreso)))
        {
            // Creo que es IMPOSIBLE :O
            //  ingreso->next->next= ingreso->next;
            //  ingreso->next = ingreso
            return;
        }
        else
        {
            // Iteramos sobre la lista
            ingreso->next = ingreso->next->next;
        }
    }
}

void eliminarEstudiante(ListaDeEstudiantes *list, Estudiante *estudiante)
{
    NodoEstudiante *actual = list->head;
    NodoEstudiante *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || actual->datos->legajo != estudiante->legajo))
    {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL)
    {
        if (list->head)
        {
            printf("Lista vacia \n");
        }
        else
        {
            printf("No se encontro el elemento en la lista \n");
        }
    }
    else
    {
        if (list->head == actual)
        {
            list->head = actual->next;
        }
        else
        {
            anterior->next = actual->next;
        }

        free(actual);
    }
    list->size--;
}

// Sin Usar
/// @param list
/// @param edad
/// @return Devuelve el primer estudiante que se encuentra en la lista a partir de una edad
Estudiante *getEstudiantePorLegajo(ListaDeEstudiantes *list, int legajo)
{
    NodoEstudiante *cursor = list->head;
    while (cursor != NULL)
    {
        if (getLegajo(GetEstudiante(cursor)) == legajo)
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
void imprimirEstudiantesPorRangoDeEdad(ListaDeEstudiantes *list, int edadMin, int edadMax)
{
    NodoEstudiante *cursor = list->head;
    if (cursor == NULL)
    {
        printf("El sistema no tiene estudiantes.\n");
    }
    while (cursor != NULL)
    {
        if (edadMin <= getEdad(GetEstudiante(cursor)) && getEdad(GetEstudiante(cursor)) <= edadMax)
        {
            imprimirEstudiante(GetEstudiante(cursor));
        }
        cursor = cursor->next;
    }
}

void enlistarAlumnoEnMateria(Materia *materia, Estudiante *estudiante)
{
    insertarOrdenadamente(materia->alumnos, estudiante);
}

// --------------------------------------------------- Lista Materias --------------------------------------------------- //

typedef struct structListaDeMaterias
{
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaDeMaterias;

ListaDeMaterias *NewListaDeMaterias()
{
    ListaDeMaterias *list = (Materia *)malloc(sizeof(ListaDeMaterias));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

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
