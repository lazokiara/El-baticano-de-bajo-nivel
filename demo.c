#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs/ListaStructs/Lista.h"

int main()
{
    int opcion = 0;
    ListaDeEstudiantes *lista_de_estudiante = NewListaDeEstudiante();

    while (opcion != 5)
    {
        printf("Ingrese la opcion del menu: \n 1: Ingresar Alumno. \n 2: Listar Alumnos. \n 3: Buscar alumno \n 5: Cerrar menu \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            printf("Lista alumno\n ------------------------- \n \n");
            char nombre[20];
            int edad;
            printf("Ingrese nombre y edad del estudiante a registrar: ");
            scanf("%s %d", nombre, &edad);

            Estudiante *alumno = NewEstudiante(nombre, edad);
            insertarOrdenadamente(lista_de_estudiante, alumno);

            printf("Estudiante %s registrado correctamente \n", alumno->nombre);
            printf("Cantidad de alumnos: %d \n", lista_de_estudiante->size);
            printf("\n");
            break;
        }
        case 2:
        {
            printf("Listar Estudiantes\n------------------------- \n \n");

            if (lista_de_estudiante->size < 1)
            {
                printf("El sistema no tiene estudiantes.\n");
                printf("\n");
                break;
            }

            NodoEstudiante *cursor = lista_de_estudiante->head;
            for (int i = 0; i < SizeOf(lista_de_estudiante); i++)
            {
                Estudiante *estudiante = GetEstudiante(cursor);
                printf("Estudiante: %s; Edad: %d \n", getNombreDelEstudiante(estudiante), getEdadDelEstudiante(estudiante));
                cursor = cursor->next;
            }
            printf("\n");
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
            imprimirEstudiantesPorEdad(lista_de_estudiante, edad_buscada);
            printf("\n");
            break;
        }
        case 4:
        {
            printf("Opcion 4\n");
            printf("\n");
            break;
        }
        case 5:
        {
            printf("Cerrando menu\n ------------------------- \n \n");
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
        //system("cls");
    }

    return 0;
}
