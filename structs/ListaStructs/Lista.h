#include "Nodo.h"
#include <stdlib.h> // Incluimos stdlib.h para malloc

typedef struct structLista {
    Nodo *head;
    Nodo *tail;
    int size;
} Lista;

Lista* NewLista() {
    Lista* list = malloc(sizeof(Lista));
    if (list == NULL) {
        return NULL; // Manejo de error si malloc falla
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void inserInicio(Lista *list, Estudiante* entrada) {
    Nodo *node = NewNodo(entrada);
    if (node == NULL) {
        return; // Manejo de error si NewNodo falla
    }
    if (SizeOf(list) == 0) {
        list->head = node; // Usamos node en lugar de entrada
        list->tail = node; // Usamos node en lugar de entrada
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

void inserFinal(Lista *list, Estudiante *entrada) {
    Nodo *node = NewNodo(entrada);
    if (node == NULL) {
        return; // Manejo de error si NewNodo falla
    }
    if (SizeOf(list) == 0) {
        list->head = node; // Usamos node en lugar de entrada
        list->tail = node; // Usamos node en lugar de entrada
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

Estudiante* getEstudiantePorEdad(Lista* list, int edad) {
    Nodo *cursor = list->head;
    while (cursor != NULL) {
        if (getEdadDelEstudiante(GetEstudiante(cursor)) == edad) {
            return GetEstudiante(cursor);
        }
        cursor = cursor->next; // Avanzamos el cursor
    }
    return NULL;
}

int SizeOf(Lista *list) {
    return list->size;
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
