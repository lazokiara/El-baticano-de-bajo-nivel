#include "Nodo.h"
#include <stdlib.h> // Incluimos stdlib.h para malloc

typedef struct structLista
{
    Nodo *head;
    Nodo *tail;
    int size;
} Lista;

Lista *NewLista()
{
    Lista *list = (Estudiante *)malloc(sizeof(Lista));
    // if (list == NULL) {
    //     return NULL; // Manejo de error si malloc falla
    // }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOf(Lista *list)
{
    return list->size;
}
/// @brief Inserta un estudiante a la cabeza de la lista
/// @param list
/// @param entrada
void inserInicio(Lista *list, Estudiante *entrada)
{
    Nodo *node = NewNodo(entrada);
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
void inserFinal(Lista *list, Estudiante *entrada)
{
    Nodo *node = NewNodo(entrada);
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
void insertarOrdenadamente(Lista *list, Estudiante *entrada)
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
    Nodo *ingreso = NewNodo(entrada);
    ingreso->next = list->head;
    //Nodo *cursor = NewNodo(list->head);

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


// FALTA
void eliminarEstudiante(Lista *list, Estudiante *estudiante)
{


    Nodo* iterador = NewNodo(estudiante);
    
    if (getNombre(GetEstudiante(iterador)) == getNombre(GetEstudiante(list->head))  && getApellido(GetEstudiante(iterador))== getApellido(GetEstudiante(list->head)))
    {
        list->head->next; 
        free(list->head);
        free(iterador);
        
    }
    
    iterador->next = list->head;

    while (iterador->next != NULL)
    {
        if (getNombre(GetEstudiante(iterador->next->next)) == getNombre(GetEstudiante(iterador)) && getApellido(GetEstudiante(iterador->next))== getApellido(GetEstudiante(iterador)))
        {
           
        }
        
    }
    
}

// Sin Usar
/// @param list
/// @param edad
/// @return Devuelve el primer estudiante que se encuentra en la lista a partir de una edad
Estudiante *getEstudiantePorEdad(Lista *list, int edad)
{
    Nodo *cursor = list->head;
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

/// @brief Imprime todos los estudiantes que tengan la edad ingresada
/// @param list
/// @param edad
void imprimirEstudiantesPorEdad(Lista *list, int edad)
{
    Nodo *cursor = list->head;
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
