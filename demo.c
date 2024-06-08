#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs/ListaStructs/Lista.h"

void loadingBar()
{
    int i;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
    for (i = 0; i < 26; i++)
    {
        printf("%c", 177);
        fflush(stdout);
        usleep(100000); // 100ms delay
    }
    printf("\r");
    printf("\t\t\t\t\t");
    for (i = 0; i < 26; i++)
    {
        printf("%c", 219);
        fflush(stdout);
        usleep(100000); // 100ms delay
    }
}

int main()
{
    int opcion_principal = 0;
    ListaDeEstudiantes *lista_de_estudiante = NewListaDeEstudiante();
    ListaDeMaterias *lista_de_materias = NewListaDeMaterias();

    while (opcion_principal != 3)
    {
        printf("Ingrese la opcion del menu \n 1: Acceder a lista de alumnos. \n 2: Acceder a lista de materias. \n 3: Cerrar menu. \n");
        scanf("%d", &opcion_principal);
        switch (opcion_principal)
        {
        case 1:
        {
            int opcion_alumnos = 0;
            while (opcion_alumnos != 5)
            {
                printf("Ingrese la opcion del menu: \n 1: Ingresar Alumno. \n 2: Listar Alumnos. \n 3: Buscar alumno. \n 4: Eliminar alumno: \n 5: Volver al menu principal \n");
                scanf("%d", &opcion_alumnos);

                switch (opcion_alumnos)
                {
                case 1:
                {
                    printf("Agregar alumno\n ------------------------- \n");
                    char nombre[20];
                    char apellido[20];
                    int edad;
                    int legajo;
                    printf("\nIngrese Nombre y Apellido del estudiante a registrar: ");
                    scanf("%s %s", nombre, apellido);
                    printf("\nIngrese la Edad: ");
                    scanf("%d", &edad);
                    printf("\nIngrese el Legajo: ");
                    scanf("%d", &legajo);
                    Estudiante *yaExiste = getEstudiantePorLegajo(lista_de_estudiante, legajo);
                    if (yaExiste != NULL)
                    {
                        printf("\nEl legajo ya pertenece a otro alumno. No se ingresara al alumno.\n\n");
                        break;
                    }
                    Estudiante *alumno = NewEstudiante(nombre, apellido, edad, legajo);

                    inserFinal(lista_de_estudiante, alumno);

                    printf("Estudiante %s %s registrado correctamente \n", getNombre(alumno), getApellido(alumno));
                    printf("Cantidad de alumnos: %d \n", lista_de_estudiante->size);
                    printf("\n");
                    break;
                }
                case 2:
                {
                    printf("Listar Estudiantes\n------------------------- \n \n");

                    if (lista_de_estudiante->size < 1 || lista_de_estudiante->head == NULL)
                    {
                        printf("El sistema no tiene estudiantes.\n");
                        printf("\n");
                    }
                    else
                    {
                        NodoEstudiante *cursor = lista_de_estudiante->head;
                        while (cursor != NULL)
                        {
                            Estudiante *estudiante = GetEstudiante(cursor);
                            imprimirEstudiante(estudiante);
                            cursor = cursor->next;
                        }
                        printf("\n");
                    }
                    break;
                }
                case 3:
                {
                    printf("Buscar Alumnos por rango de edad\n ------------------------- \nIngrese rango de edad (minimo y maximo):  ");
                    int edad_min;
                    int edad_max;
                    scanf("%d %d", &edad_min, &edad_max);
                    printf("\n\n");
                    if (edad_min < 1)
                    {
                        printf("Edad minima invalida.\n");
                        printf("\n");
                        break;
                    }
                    printf("Listado de Estudiantes por Rango de edad: \n");
                    imprimirEstudiantesPorRangoDeEdad(lista_de_estudiante, edad_min, edad_max);
                    printf("\n");
                    break;
                }
                case 4:
                {
                    printf("Eliminar alumno\n ------------------------- \n Ingrese legajo: ");
                    int legajo_buscado;
                    scanf("%d", &legajo_buscado);
                    Estudiante *alumno = getEstudiantePorLegajo(lista_de_estudiante, legajo_buscado);
                    if (alumno == NULL)
                    {
                        printf("El Legajo ingresado no pertenece a ningun estudiante del sistema.");
                        break;
                    }
                    else
                    {
                        printf("Estudiante a eliminar: ");
                        imprimirEstudiante(alumno);
                        printf("\n 1: Confirmar eliminarcion. \n 2: Cancelar. \n");
                        int confirmacion;
                        scanf("%d", &confirmacion);
                        if (confirmacion == 1)
                        {
                            eliminarEstudiante(lista_de_estudiante, alumno);
                            printf("Estudiante eliminado\n ------------------------- \n \n");
                        }
                        else if (confirmacion == 2)
                        {
                            printf("Cancelando... \n");
                        }
                        else
                        {
                            printf("Intente nuevamente. \n");
                        }
                    }

                    break;
                }
                case 5:
                {
                    printf("Regresando...\n ------------------------- \n \n");
                    printf("\n");
                    break;
                }
                default:
                {
                    printf("Opcion invalida. Ingrese un numero del 1 al 5\n");
                    printf("\n");
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            int opcion_materia;
            while (opcion_materia != 6)
            {
                printf("Ingrese la opcion del menu: \n 1: Ingresar Materia. \n 2: Listar Materias. \n 3: Eliminar Materia. \n 4: Anotar alumnos. \n 5: Obtener alumnos cursantes. \n 6: Cerrar menu \n");
                scanf("%d", &opcion_materia);
                switch (opcion_materia)
                {
                case 1:
                {
                    printf("Lista materias\n ------------------------- \n \n");
                    char nombre[20];
                    printf("Ingrese el nombre de la materia: ");
                    scanf("%s ", nombre);
                    Materia *materia = NewMateria(nombre);
                    addMateria(lista_de_materias, materia);
                    printf("Materia %s registrada correctamente \n", getNombreMateria(materia));
                    printf("Cantidad de materias: %d \n", lista_de_materias->size);
                    printf("\n");
                    break;
                }
                case 2:
                {
                    printf("Listar materias\n------------------------- \n \n");

                    if (lista_de_materias->size < 1 || lista_de_materias->head == NULL)
                    {
                        printf("El sistema no tiene materias registradas.\n");
                        printf("\n");
                    }
                    else
                    {
                        NodoMateria *mat = lista_de_materias->head;
                        while (mat != NULL)
                        {
                            Materia *materia = GetMateria(mat);
                            imprimirMateria(materia);
                            mat = mat->next;
                        }
                        printf("\n");
                    }
                    break;
                }
                case 6:
                {
                    printf("Regresando al menu.");
                    break;
                }

                default:
                {
                    printf("Opcion invalida. Ingrese un numero del 1 al 5\n");
                    printf("\n");
                    opcion_materia = 0;
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            printf("Cerrando menu\n ------------------------- \n \n");
            loadingBar();
            printf("\n");
            break;
        }
        default:
            printf("Opcion invalida. Ingrese un numero del 1 al 3\n");
            printf("\n");
            opcion_principal = 0;
            break;
        }
    }

    // system("cls");

    return 0;
}
