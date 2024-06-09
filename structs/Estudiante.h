#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct structEstudiante
{
    char *nombre;
    char *apellido;
    int edad;
    int legajo;
} Estudiante;

Estudiante *NewEstudiante(char *nom, char *ap, int ed, int legajo);
void imprimirEstudiante(Estudiante *estudiante);
int getEdad(Estudiante *alumn);
int getLegajo(Estudiante *alumn);
char *getNombre(Estudiante *alumn);
char *getApellido(Estudiante *alumn);

Estudiante *NewEstudiante(char *nom, char *ap, int ed, int leg)
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
    estudiante->legajo = leg;
    return estudiante;
}

void imprimirEstudiante(Estudiante *estudiante)
{
    if (estudiante != NULL)
    {
        printf("Estudiante: %s %s \n----Edad: %d\n----Legajo: %d \n\n", getNombre(estudiante), getApellido(estudiante), getEdad(estudiante), getLegajo(estudiante));
    }
}

int getEdad(Estudiante *alumn)
{
    return alumn->edad;
}

int getLegajo(Estudiante *alumn)
{
    return alumn->legajo;
}

char *getNombre(Estudiante *alumn)
{
    return alumn->nombre;
}

char *getApellido(Estudiante *alumn)
{
    return alumn->apellido;
}

const char *nombres[12] = {"Ignacio", "Agustin", "Kiara", "Martina", "Ruperta", "Juan", "Maria", "Carlos", "Anastasio", "Adolfo", "Ana", "Luis"};
const char *apellidos[12] = {"Lobo", "Geraghty", "Lazo", "Paris", "Isla", "Garcia", "Perez", "Lopez", "Rodriguez", "Martinez", "Cavani", "Mohamed"};

char *generarNombreAleatorio()
{
    int indice = rand() % 12;
    char *nombre = (char *)malloc((strlen(nombres[indice]) + 1) * sizeof(char));
    strcpy(nombre, nombres[indice]);
    return nombre;
}

char *generarApellidoAleatorio()
{
    int indice = rand() % 12;
    char *apellido = (char *)malloc((strlen(apellidos[indice]) + 1) * sizeof(char));
    strcpy(apellido, apellidos[indice]);
    return apellido;
}

int generarEdadAleatoria()
{
    return rand() % 73 + 18; // Edad entre 18 y 90 años
}

int generarLegajoAleatorio()
{
    return rand() % 100000;
}