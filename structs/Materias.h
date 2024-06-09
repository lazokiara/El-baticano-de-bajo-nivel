#include <stdlib.h>
//borrar? struct ListaDeEstudiantes;

typedef struct structMateria{
    char *nombre;
    struct structListaDeEstudiantes *alumno;
    struct structNodoEstudiante *alumnos;
}Materia;

Materia *NewMateria(char *nom){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(materia->nombre,nom);
    return materia;
}
char* getNombreMateria(Materia *m){
    return m->nombre;
}
void imprimirMateria (Materia *materia){
    printf("\nMateria: \n Nombre: %s", materia->nombre);
}
void getCursantes (Materia *m){

}
