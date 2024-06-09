#include <stdlib.h>
//borrar? struct ListaDeEstudiantes;

typedef struct structMateria{
    char *nombre;
    struct ListaDeEstudiantes *alumnos;
    int catn_alumnos;
    // struct structListaDeEstudiantes *alumno;
    // struct structNodoEstudiante *alumnos;
}Materia;

Materia *NewMateria(char *nom){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(materia->nombre,nom);
    materia->alumnos = NULL;
    materia->catn_alumnos = 0;
    return materia;
}
char* getNombreMateria(Materia *m){
    return m->nombre;
}
void imprimirMateria (Materia *materia){
    printf("\nMateria: \n Nombre: %s \n Cantidad de alumnos: %d ", materia->nombre, materia->catn_alumnos);
}
void getCursantes (Materia *m){

}
