#include <stdio.h>
#include "structs/ListaStructs/Lista.h"

int main()
{

    int opcion = 0;

    Lista *mi_lista = NewLista();

    while (opcion != 5)
    {
        printf("Ingrese la opcion de menu: \n 1: Ingresar Alumno. \n 5: Cerrar menu \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:

            printf("Opcion 1");
            char nombre[20];
            int edad;
            printf("Prueba\n");
            printf("Ingrese nombre y edad del estudiante a registrar:");
            // gets(nombre);
            scanf("%s %d", nombre, &edad);
            Estudiante *alumno = NewEstudiante(nombre, edad);
            printf("Estudiante %s registrado correctamente \n", alumno->nombre);
            inserInicio(mi_lista, alumno);
            printf("Cantidad de alumnos: %d \n", mi_lista->size);

            
            break;
        case 1:
            printf("Opcion 2\n");
            break;
        case 2:
            printf("Opcion 3\n");
            break;
        case 3:
            printf("\n");
            break;

        case 5:
            printf("Opcion 5\n");
            printf("Cerrarndo menu\n");
            break;

        default:
            printf("Opcion invalida");
            break;
        }
    }

    return 0;
}
// Lista* mi_lista = NewLista();
// Estudiante *nacho = NewEstudiante("Ignacio",20);
// Estudiante *agus = NewEstudiante("Agustin",25);
// char nombre[10];
// int edad;
// printf("Prueba\n");
// printf("Ingrese nombre y edad del estudiante a registrar:");
// gets(nombre);
// scanf("%s %d", nombre, &edad );
// Estudiante *alumno = NewEstudiante(nombre, edad);
// printf("Estudiante %s registrado correctamente \n",alumno->nombre );
// inserInicio(mi_lista,alumno);
// printf("Cantidad de alumnos: %d \n",mi_lista->size );

// printf("%s \n",agus->nombre );
// printf("%d \n",agus->edad );

// printf("\n\n");

// Estudiante *kiara = NewEstudiante("Kiara",30);

// inserInicio(mi_lista,nacho);
// inserInicio(mi_lista,agus);
// inserFinal(mi_lista,kiara);

// Estudiante* prueba = getEstudiantePorEdad(mi_lista,20);

// printf("%s", prueba->nombre);

// // Nodo* cursor = mi_lista->head;
// // while (cursor!= NULL)
// // {
// //     /* code */
// // }

// printf("el estudiante prueba %s \n", mi_lista->head->datos->nombre);
// printf("su edad es: %d \n", mi_lista->head->datos->edad);

// printf("el estudiante prueba %s \n", mi_lista->tail->datos->nombre);
// printf("su edad es: %d \n", mi_lista->tail->datos->edad);
