 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "structs/ListaStructs/Lista.h"

void loadingBar()
{
    int i;
    printf("\n");
    printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
    for (i = 0; i < 26; i++)
    {
        printf("%c", 177);
        fflush(stdout);
        usleep(100000);
    }
    printf("\r");
    printf("\t\t\t\t\t");
    for (i = 0; i < 26; i++)
    {
        printf("%c", 219);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n\n");
}

int main()
{
    int opcion_principal;
    ListaDeEstudiantes *lista_de_estudiante = NewListaDeEstudiante();
    ListaDeMaterias *lista_de_materias = NewListaDeMaterias();

    while (opcion_principal != 3)
    {
        printf("Ingrese la opcion del menu \n \n 1: Acceder a lista de alumnos. \n 2: Acceder a lista de materias. \n 3: Cerrar menu. \n");
        scanf("%d", &opcion_principal);
        system("cls");
        switch (opcion_principal)
        {

        case 1:
        {
            int opcion_alumnos = 0;
            while (opcion_alumnos != 7)
            {
                printf("Ingrese la opcion del menu: \n 0: Ingresar 10 alumnos aleatorios. \n 1: Ingresar Alumno. \n 2: Listar Alumnos. \n 3: Buscar alumnos. \n 4: Eliminar alumno: \n 5: Eliminar lista de alumnos. \n 6: Renombrar alumno. \n 7: Volver al menu principal \n");
                scanf("%d", &opcion_alumnos);
                system("cls");
                switch (opcion_alumnos)
                {
                case 0:
                {
                    for (int i = 0; i < 10; i++)
                    {
                        Estudiante *random_est = NewEstudiante(generarNombreAleatorio(), generarApellidoAleatorio(), generarEdadAleatoria(), generarLegajoAleatorio());
                        insertarOrdenadamente(lista_de_estudiante, random_est);
                    }
                    break;
                }
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

                    insertarOrdenadamente(lista_de_estudiante, alumno);

                    printf("Estudiante %s %s registrado correctamente \n", getNombre(alumno), getApellido(alumno));
                    printf("Cantidad de alumnos: %d \n", lista_de_estudiante->size);
                    printf("\n");
                    break;
                }
                case 2:
                {
                    printf("Listar Estudiantes\n------------------------- \n \n");

                    imprimirListaDeEstudiantes(lista_de_estudiante);
                    break;
                }
                case 3:
                {
                    printf("Buscar Alumnos.\n ------------------------- \n 1: Buscar por nombre. \n 2: Buscar por legajo. \n 3: Buscar por rango de edad. \n");
                    int opcion_busc_alum = 0;
                    scanf("%d", &opcion_busc_alum);
                    switch (opcion_busc_alum)
                    {
                    case 1:
                    {
                        char nomb[20];
                        char apel[20];
                        printf("\nIntroduzca el nombre del alumno a buscar: ");
                        scanf("%s %s", nomb, apel);

                        Estudiante *alum_busc = getEstudiantePorNombre(lista_de_estudiante, nomb, apel);
                        if (alum_busc == NULL)
                        {
                            printf("\nNo se encontro al alumno.\n");
                            break;
                        }

                        imprimirEstudiante(alum_busc);
                        break;
                    }
                    case 2:
                    {
                        printf("\nIntroduzca el legajo del alumno a buscar: ");
                        int legaj = 0;
                        scanf("%d", &legaj);

                        Estudiante *alum_busc = getEstudiantePorLegajo(lista_de_estudiante, legaj);
                        if (alum_busc == NULL)
                        {
                            printf("\nNo se encontro al alumno.\n");
                            break;
                        }

                        imprimirEstudiante(alum_busc);
                        break;
                    }
                    case 3:
                    {
                        int edad_min;
                        int edad_max;
                        printf("Ingresar rango (minimo y maximo): ");
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
                    default:
                    {
                        printf("Opcion Invalida.\n");
                        break;
                    }
                    }
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
                        printf("\n 1: Confirmar eliminacion. \n 2: Cancelar. \n");
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
                    printf("¿Desea eliminar la lista de alumnos?\n 1: Si. \n 2:No. \n ");
                    int confi = 0;
                    scanf("%d", &confi);
                    if (confi == 1)
                    {
                        loadingBar();
                        eliminarListaDeEstudiantes(lista_de_estudiante);
                        printf("Lista eliminada\n ------------------------- \n \n");
                    }
                    else if (confi == 2)
                    {
                        printf("Cancelando... \n");
                    }
                    else
                    {
                        printf("Intente nuevamente. \n");
                    }
                    break;
                }
                case 6:
                {
                    printf("Ingrese el legajo del alumno que desea renombrar: \n");
                    int legajo_buscado;
                    scanf("%d", &legajo_buscado);
                    Estudiante *estudiante_buscado = getEstudiantePorLegajo(lista_de_estudiante, legajo_buscado);
                    if (estudiante_buscado == NULL)
                    {
                        printf("El legajo ingresado no pertenece a ningun estudiante del sistema. \n");
                        break;
                    }
                    printf("Ingrese el nuevo nombre y apellido del estudiante: \n");
                    char new_nombre[50];
                    char new_apellido[50];
                    scanf("%s %s", new_nombre, new_apellido);
                    modificarNombreDeEstudiante(estudiante_buscado, new_nombre, new_apellido);
                    printf("Estudiante %s %s renombrado correctamente. \n", estudiante_buscado->nombre, estudiante_buscado->apellido);
                    break;
                }
                case 7:
                {
                    printf("Regresando...\n ------------------------- \n \n");
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
            int opcion_materia = 0;
            while (opcion_materia != 10)
            {
                printf("Ingrese la opcion del menu: \n 0: Generar materias aleatoriamente. \n 1: Ingresar Materia. \n 2: Listar Materias. \n 3: Eliminar Materia. \n 4: Eliminar lista de materias. \n 5: Cambiar nombre de materia. \n 6: Enlistar alumno en materia. \n 7: Dar de baja de la materia a un alumno. \n 8: Promediar alumno por materia. \n 9: Imprimir alumnos de materia. \n 10: Cerrar menu. \n");
                scanf("%d", &opcion_materia);
                system("cls");
                switch (opcion_materia)
                {
                case 0:
                {
                  for (int i = 0; i < 5; i++)
                    {
                        Materia *random_mat = NewMateria(generarNombreDeMateria());
                        Materia *contains = getMateriaPorNombre(lista_de_materias, getNombreMateria(random_mat));
                        if (contains == NULL)
                        {
                            addMateria(lista_de_materias, random_mat);
                        }
                    }
                    break;
                }
                case 1:
                {
                    printf("Lista materias\n ------------------------- \n \n");
                    char nombre[20];
                    printf("Ingrese el nombre de la materia: ");
                    scanf("%s", nombre);
                    Materia *contains = getMateriaPorNombre(lista_de_materias, nombre);
                    if (contains != NULL)
                    {
                        printf("La materia ya se encuentra en el sistema\n");
                        break;
                    }
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

                    if (lista_de_materias->head == NULL || lista_de_materias->size < 1)
                    {
                        printf("El sistema no tiene materias registradas.\n");
                        break;
                    }
                    else
                    {
                        NodoMateria *mat = lista_de_materias->head;
                        while (mat != NULL)
                        {
                            Materia *materia = GetMateria(mat);
                            imprimirMateria(materia);
                            printf("\n");
                            mat = mat->next;
                        }
                    }
                    printf("\n");
                    break;
                }
                case 3:
                {
                    printf("Eliminar materia\n ------------------------- \n Ingrese nombre de la materia: ");
                    char materia_buscada[50];
                    scanf("%s", materia_buscada);
                    Materia *materia = getMateriaPorNombre(lista_de_materias, materia_buscada);
                    if (materia == NULL)
                    {
                        printf("El nombre ingresado no pertenece a ninguna materia del sistema. \n");
                        break;
                    }
                    else
                    {
                        printf("Materia a eliminar: ");
                        imprimirMateria(materia);
                        printf("\n 1: Confirmar eliminacion. \n 2: Cancelar. \n");
                        int confirmacion;
                        scanf("%d", &confirmacion);
                        if (confirmacion == 1)
                        {
                            eliminarMateria(lista_de_materias, materia);
                            printf("Materia eliminada\n ------------------------- \n \n");
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
                case 4:
                {

                    printf("¿Desea eliminar la lista de materias?\n 1: Si. \n 2: No. \n ");
                    int confi = 0;
                    scanf("%d", &confi);
                    if (confi == 1)
                    {
                        loadingBar();
                        clearListaDeMaterias(lista_de_materias);
                        printf("Lista eliminada\n ------------------------- \n \n");
                    }
                    else if (confi == 2)
                    {
                        printf("Cancelando... \n");
                    }
                    else
                    {
                        printf("Intente nuevamente. \n");
                    }
                    break;
                }
                case 5:
                {

                    printf("Ingrese la materia que desea renombrar: \n");
                    char nombre_buscado[50];
                    scanf("%s", nombre_buscado);
                    Materia *materia_buscada = getMateriaPorNombre(lista_de_materias, nombre_buscado);
                    if (materia_buscada == NULL)
                    {
                        printf("El nombre ingresado no pertenece a ninguna materia del sistema. \n");
                        break;
                    }
                    printf("Ingrese el nuevo nombre de la materia: \n");
                    char new_nombre[50];
                    scanf("%s", new_nombre);
                    modificarNombreMateria(materia_buscada, new_nombre);
                    printf("Materia %s renombrada correctamente. \n", materia_buscada->nombre);
                    break;
                }
                case 6:
                {
                    char nombre[20];
                    printf("Ingrese la materia en la que desea ingresar el alumno: \n ");
                    scanf("%s", nombre);
                    Materia *materia = getMateriaPorNombre(lista_de_materias, nombre);
                    if (materia == NULL)
                    {
                        printf("Materia no existe");
                        break;
                    }
                    int legajo;
                    printf("Ingrese el legajo del alumno a enlistar: \n");
                    scanf("%d", &legajo);
                    Estudiante *estudiante = getEstudiantePorLegajo(lista_de_estudiante, legajo);
                    if (estudiante == NULL)
                    {
                        printf("Estudiante no registrado en el sistema \n");
                        break;
                    }

                    enlistarAlumnoEnMateria(materia, estudiante);
                    printf("Alumno %s %s enlistado correctamente. \n Cantidad de alumnos en %s: %d \n", estudiante->nombre, estudiante->apellido, materia->nombre, materia->catn_alumnos);
                    break;
                }
                case 7:
                {
                    char nombre[20];
                    printf("Ingrese la materia de la que desea eliminar el alumno: \n ");
                    scanf("%s", nombre);
                    Materia *materia = getMateriaPorNombre(lista_de_materias, nombre);
                    if (materia == NULL)
                    {
                        printf("Materia no existe");
                        break;
                    }
                    int legajo;
                    printf("Ingrese el legajo del alumno a dar de baja: \n");
                    scanf("%d", &legajo);
                    ListaDeEstudiantes *lista_aux = NewListaDeEstudiante();
                    lista_aux = materia->alumnos;
                    Estudiante *estudiante = getEstudiantePorLegajo(lista_aux, legajo);
                    if (estudiante == NULL)
                    {
                        printf("Estudiante no registrado en la materia \n");
                        break;
                    }
                    printf("¿Desea eliminar al alumno %s %s de %s?\n 1: Si. \n 2: No. \n ", estudiante->nombre, estudiante->apellido, materia->nombre);
                    int confi = 0;
                    scanf("%d", &confi);
                    if (confi == 1)
                    {
                        loadingBar();
                        eliminarAlumoDeMateria(materia, estudiante);
                        printf("Alumno eliminado\n ------------------------- \n \n");
                    }
                    else if (confi == 2)
                    {
                        printf("Cancelando... \n");
                    }
                    else
                    {
                        printf("Intente nuevamente. \n");
                    }

                    break;
                }
                case 8:
                {
                    printf("Ingrese la materia: \n");
                    char mat[50];
                    scanf("%s", mat);
                    Materia *materia = getMateriaPorNombre(lista_de_materias, mat);
                    if (materia == NULL)
                    {
                        printf("La materia no existe.\n");
                        break;
                    }
                    printf("Ingrese el legajo del alumno que rinde: \n");
                    int leg;
                    scanf("%d", &leg);
                    ListaDeEstudiantes *lista_aux = NewListaDeEstudiante();
                    lista_aux = materia->alumnos;
                    Estudiante *estudiante = getEstudiantePorLegajo(lista_aux, leg);
                    if (estudiante == NULL)
                    {
                        printf("Estudiante no registrado. \n");
                        break;
                    }
                    printf("Ingrese la nota del primer parcial: \n");
                    int p1;
                    scanf("%d", &p1);
                    if (p1 < 0 || p1 > 10)
                    {
                        printf("Nota invalida. \n");
                        break;
                    }
                    printf("Ingrese la nota del segundo parcial: \n");
                    int p2;
                    scanf("%d", &p2);
                    if (p2 < 0 || p2 > 10)
                    {
                        printf("Nota invalida. \n");
                        break;
                    }
                    printf("Ingrese la nota del final: \n");
                    int final;
                    scanf("%d", &final);
                    if (final < 0 || final > 10)
                    {
                        printf("Nota invalida. \n");
                        break;
                    }
                    float promedio = (p1 + p2 + final) / 3;
                    rendirMateria(materia, estudiante, promedio);
                    break;
                }
                case 9:
                {
                    char mate_busc[20];
                    printf("\nIngrese el nombre de la materia por imprimir: \n");
                    scanf("%s", mate_busc);

                    Materia *mate_imprim = getMateriaPorNombre(lista_de_materias, mate_busc);
                    if (mate_imprim == NULL)
                    {
                        printf("Materia inexistente.\n");
                        break;
                    }
                    printf("Imprimir lista de alumnos de la materia: \n 1: Todos los alumnos.\n 2: Alumnos aprobados.\n 3: Alumnos desaprobados.\n");
                    int opcion_menu_imprimir = 0;
                    scanf("%d", &opcion_menu_imprimir);
                    switch (opcion_menu_imprimir)
                    {
                    case 1:
                    {
                        ListaDeEstudiantes *lista_aux = NewListaDeEstudiante();
                        lista_aux = mate_imprim->alumnos;
                        imprimirListaDeEstudiantes(lista_aux);
                        break;
                    }
                    case 2:
                    {
                        ListaDeEstudiantes *lista_aux = NewListaDeEstudiante();
                        lista_aux = mate_imprim->alumnos_aprobados;
                        imprimirListaDeEstudiantes(lista_aux);
                        break;
                    }
                    case 3:
                    {
                        ListaDeEstudiantes *lista_aux = NewListaDeEstudiante();
                        lista_aux = mate_imprim->alumnos_desaprobados;
                        imprimirListaDeEstudiantes(lista_aux);
                        break;
                    }
                    default:
                    {
                        printf("Opcion invalida, regresando...\n");
                        break;
                    }
                    }

                    break;
                }
                case 10:
                {
                    printf("Regresando \n");
                    break;
                }
                default:
                {
                    printf("Opcion invalida. Ingrese un numero del 1 al 7\n");
                    printf("\n");
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
            break;
        }
        default:
        {
            printf("Opcion invalida. Ingrese un numero del 1 al 3\n");
            printf("\n");
            break;
        }
        }
        // system("cls");
    }

    return 0;
}
