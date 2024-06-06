#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct structEstudiante
{
    char *nombre;
    char *apellido;
    int edad;

} Estudiante;

Estudiante *NewEstudiante(char *nom, char *ap, int ed);
void imprimirEstudiante(Estudiante* estudiante);
int getEdad(Estudiante *alumn);
char* getNombre(Estudiante *alumn);
char *getApellido(Estudiante *alumn);

Estudiante *NewEstudiante(char *nom, char *ap, int ed)
{
    Estudiante *estudiante;
    estudiante = (Estudiante *)malloc(sizeof(Estudiante));
    // if (estudiante == NULL)
    // {
    //     printf("Error al asignar memoria\n");
    //     exit(1);
    // }
    estudiante->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    estudiante->apellido = (char *)malloc((strlen(ap) + 1) * sizeof(char));
    // if (estudiante->nombre == NULL || estudiante->apellido == NULL)
    // {
    //     printf("Error al asignar memoria\n");
    //     free(estudiante);
    //     exit(1);
    // }
    strcpy(estudiante->nombre, nom);
    strcpy(estudiante->apellido, ap);
    estudiante->edad = ed;
    return estudiante;
}

void imprimirEstudiante(Estudiante* estudiante){
    printf("Estudiante: %s %s; Edad: %d\n",getNombre(estudiante),getApellido(estudiante),getEdad(estudiante));
}

int getEdad(Estudiante *alumn)
{
    return alumn->edad;
}

char* getNombre(Estudiante *alumn)
{
    return alumn->nombre;
}

char *getApellido(Estudiante *alumn)
{
    return alumn->apellido;
}
