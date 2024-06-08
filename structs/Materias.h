#include <stdlib.h>
struct ListaDeEstudiantes;

typedef struct structMateria{
    char *nombre;
    struct structListaDeEstudiantes *alumnos;
}Materia;

Materia *NewMateria(char *nom){
    Materia *materia;
    materia = (Materia*)malloc(sizeof(Materia));
    materia->nombre = nom;
    return materia;
}
char getNombreMateria(Materia *m){
    return m->nombre;
}
void imprimirMateria (Materia *materia){
    printf("Materia: %s", getNombreMateria(materia));
}
void getCursantes (Materia *m){

}
