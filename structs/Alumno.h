#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "Materias.h"

typedef struct structEstudiante {
    struct structEstudiante *prox;
    struct Materia *materias;
    char *nombre;
    int edad;

} Estudiante;

Estudiante *NewEstudiante(char *nom, int ed) {
    Estudiante *estudiante;
    estudiante = malloc(sizeof(Estudiante));
    estudiante->edad = ed;
    estudiante->nombre = nom;
    estudiante->prox = NULL;
    return estudiante;
}
/*
void eliminarEstudiante(Estudiante **lista, char estudiante){
    Estudiante *aux = *lista;
    if (aux != NULL && aux->nombre == estudiante) {
        Estudiante *temp = aux;
        *lista = aux->prox;
        free(temp);
        return;
    }
     while (aux != NULL && aux->prox != NULL) {
        if (aux->prox->nombre == estudiante) {
            Estudiante *temp = aux->prox;
            aux->prox = aux->prox->prox;
            free(temp);
            return;
        }
        aux = aux->prox;
    }
}
void modificarAlumno(Estudiante **lista, char materia){}

void enlistarAlumnos(Estudiante **lista){}

void buscarAlumno(Estudiante **lista, char alumno){}

void buscarAlumnoEdad(Estudiante **lista, int edad){}

void anotarseEnLaMateria(Estudiante **alumnos, Materia **materias, char alumno, char materia){}

void rendirMateria(Estudiante **alumnos, Materia **materias, char alumno, char materia){}
*/