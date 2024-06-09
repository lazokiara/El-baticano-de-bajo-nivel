#include <stdlib.h>

typedef struct structMateria{
    char *nombre;
    struct ListaDeEstudiantes *alumnos;
    int catn_alumnos;
    struct ListaDeEstudiantes *alumnos_aprobados;
    int catn_alumnos_aprobados;
    struct ListaDeEstudiantes *alumnos_desaprobados;
    int catn_alumnos_desaprobados;
}Materia;

Materia *NewMateria(char *nom){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(materia->nombre,nom);
    materia->alumnos = NULL;
    materia->catn_alumnos = 0;
    materia->alumnos_aprobados = NULL;
    materia->catn_alumnos_aprobados = 0;
    materia->alumnos_desaprobados = NULL;
    materia->catn_alumnos_desaprobados = 0;
    return materia;
}
char* getNombreMateria(Materia *m){
    return m->nombre;
}
void imprimirMateria (Materia *materia){
    printf("\nMateria: \n Nombre: %s \n Cantidad de alumnos: %d ", materia->nombre, materia->catn_alumnos);
}
