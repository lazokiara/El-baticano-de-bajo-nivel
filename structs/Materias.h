#include <stdlib.h>

typedef struct structMateria
{
    char *nombre;
    struct ListaDeEstudiantes *alumnos;
    int catn_alumnos;
    struct ListaDeEstudiantes *alumnos_aprobados;
    int catn_alumnos_aprobados;
    struct ListaDeEstudiantes *alumnos_desaprobados;
    int catn_alumnos_desaprobados;
} Materia;

Materia *NewMateria(char *nom)
{
    Materia *materia;
    materia = (Materia *)malloc(sizeof(Materia));
    materia->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(materia->nombre, nom);
    materia->alumnos = NULL;
    materia->catn_alumnos = 0;
    materia->alumnos_aprobados = NULL;
    materia->catn_alumnos_aprobados = 0;
    materia->alumnos_desaprobados = NULL;
    materia->catn_alumnos_desaprobados = 0;
    return materia;
}
char *getNombreMateria(Materia *m)
{
    return m->nombre;
}
void imprimirMateria(Materia *materia)
{
    if (materia != NULL)
    {

        int porc_aprob = 0;
        int porc_desaprob = 0;
        if (materia->catn_alumnos > 1)
        {
            porc_aprob = (materia->catn_alumnos_aprobados * 100) / materia->catn_alumnos;
            porc_desaprob = (materia->catn_alumnos_desaprobados * 100) / materia->catn_alumnos;
        }
        printf("\nMateria: \n----Nombre: %s \n----Cantidad de alumnos: %d \n----Porcentaje de alumnos aprobados: %d \n----Porcentaje de alumnos desaprobados: %d", materia->nombre, materia->catn_alumnos, porc_aprob, porc_desaprob);
    }
}

char *materias[10] = {"Matematica Discreta", "AYP1", "AYP2", "Programacion de Bajo Nivel", "Diseño Logico", "Algebra I", "Ingles Basico", "Ingles Tecnico", "Estructura de Datos", "Cultura Contemporanea"};

char *generarNombreDeMateria()
{
    int i = rand() % 10;
    char *materia = (char *)malloc((strlen(materias[i]) + 1) * sizeof(char));
    strcpy(materia, materias[i]);
    return materia;
}