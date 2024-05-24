#include "Nodo.h"

typedef struct structLista {
    Nodo *head;
    Nodo *tail;
    int size;
} Lista;


Lista *NewLista() {
    Lista* list;
    malloc(sizeof(Lista));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void inserInicio(Lista *list, Estudiante* entrada){
    Nodo *node = NewNodo(entrada);
    node->next = list->head;
    list->head = node;
    list->size++;
}
void inserFinal(Lista *list, Estudiante *entrada) {
    Nodo *node = NewNodo(entrada);
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

int Size(Lista *list) {
    return  list->size;
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