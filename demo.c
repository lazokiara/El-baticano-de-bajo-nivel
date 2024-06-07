#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs/ListaStructs/Lista.h"

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
                    printf("Lista alumno\n ------------------------- \n \n");
                    char nombre[20];
                    char apellido[20];
                    int edad;
                    printf("Ingrese Nombre, Apellido y Edad del estudiante a registrar: ");
                    scanf("%s %s %d", nombre, apellido, &edad);

                    Estudiante *alumno = NewEstudiante(nombre, apellido, edad);

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
                    printf("Buscar Alumno\n ------------------------- \n Ingrese edad: ");
                    int edad_buscada;
                    scanf("%d", &edad_buscada);

                    if (edad_buscada < 1)
                    {
                        printf("Edad invalida.\n");
                        printf("\n");
                        break;
                    }
                    printf("\n");
                    imprimirEstudiantesPorEdad(lista_de_estudiante, edad_buscada);
                    printf("\n");
                    break;
                }
                case 4:
                {
                    printf("Eliminar alumno\n ------------------------- \n Ingrese edad: ");
                    int edad_buscada;
                    scanf("%d", &edad_buscada);
                    Estudiante *alumno = getEstudiantePorEdad(lista_de_estudiante, edad_buscada);
                    eliminarEstudiante(lista_de_estudiante, alumno);
                    printf("Estudiante eliminado\n ------------------------- \n \n");
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
                break;
            }
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            printf("\nCerrando menu... Hasta la proxima! \n \n");
            break;
        }
        default:
        {
            printf("Opcion invalida. Ingrese un numero del 1 al 5\n");
            printf("\n");
            break;
        }
        }

        // system("cls");
    }

    return 0;
}
