#include "Nodo.h"
#include <stdlib.h> // Incluimos stdlib.h para malloc

typedef struct structLista {
    Nodo *head;
    Nodo *tail;
    int size;
} Lista;

Lista* NewLista() {
    Lista* list = (Estudiante*)malloc(sizeof(Lista));
    // if (list == NULL) {
    //     return NULL; // Manejo de error si malloc falla
    // }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOf(Lista *list) {
    return list->size;
}

void inserInicio(Lista *list, Estudiante* entrada) {
    Nodo *node = NewNodo(entrada);
    if (node == NULL) {
        return; 
    }
    if (SizeOf(list) == 0) {
        list->head = node; 
        list->tail = node; 
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}


/// @brief Inserta al Estudiante al inicio como nuevo Head
/// @param list 
/// @param entrada 
void inserFinal(Lista *list, Estudiante *entrada) {
    Nodo *node = NewNodo(entrada);
    if (node == NULL) {
        return; // Manejo de error si NewNodo falla
    }
    if (SizeOf(list) == 0) {
        list->head = node; 
        list->tail = node; 
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}


/// @brief Devuelve un estudiante a partir de una edad
/// @param list 
/// @param edad 
/// @return 
Estudiante* getEstudiantePorEdad(Lista* list, int edad) {
    Nodo *cursor = list->head;
    while (cursor != NULL) {
        if (getEdadDelEstudiante(GetEstudiante(cursor)) == edad) {
            return GetEstudiante(cursor);
        }
        cursor = cursor->next; 
    }
    return NULL;
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