#include "Nodo.h"
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------- Lista Estudiante --------------------------------------------------- //

typedef struct structListaDeEstudiantes
{
    NodoEstudiante *head;
    NodoEstudiante *tail;
    int size;
} ListaDeEstudiantes;

ListaDeEstudiantes *NewListaDeEstudiante()
{
    ListaDeEstudiantes *list = (ListaDeEstudiantes *)malloc(sizeof(ListaDeEstudiantes));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOfEst(ListaDeEstudiantes *list)
{
    return list->size;
}

/// @brief Inserta un estudiante a la cabeza de la lista
/// @param list
/// @param entrada
void inserInicio(ListaDeEstudiantes *list, Estudiante *entrada)
{
    NodoEstudiante *node = NewNodoEstudiante(entrada);
    if (node->datos == NULL)
    {
        return;
    }
    if (SizeOfEst(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
}

/// @brief Inserta un estudiante a la cola de la lista
/// @param list
/// @param entrada
void inserFinal(ListaDeEstudiantes *list, Estudiante *entrada)
{
    NodoEstudiante *node = NewNodoEstudiante(entrada);
    if (node->datos == NULL)
    {
        return;
    }
    if (SizeOfEst(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

/// @brief Inserta un elemento de forma ordenada. Es O(n) pero con mejoras que lo pueden agilizar a O(1)
/// @param list
/// @param entrada
void insertarOrdenadamente(ListaDeEstudiantes *list, Estudiante *entrada)
{
    if (SizeOfEst(list) < 1 || list->head->datos->edad > entrada->edad)
    {
        inserInicio(list, entrada);
        return;
    }
    else if (list->tail->datos->edad < entrada->edad)
    {
        inserFinal(list, entrada);
        return;
    }

    // Nodo a ingresar apunta al head
    NodoEstudiante *ingreso = NewNodoEstudiante(entrada);
    ingreso->next = list->head;
    // NodoEstudiante *cursor = NewNodoEstudiante(list->head);

    while (ingreso->next->next != NULL)
    {
        if (getEdad(GetEstudiante(ingreso->next->next)) >= getEdad(GetEstudiante(ingreso)))
        {
            NodoEstudiante *aux = ingreso->next->next;
            ingreso->next->next = ingreso;
            ingreso->next = aux;
            list->size++;
            return;
        }
        ingreso->next = ingreso->next->next;
    }
}

void eliminarEstudiante(ListaDeEstudiantes *list, Estudiante *estudiante)
{
    NodoEstudiante *actual = list->head;
    NodoEstudiante *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || actual->datos->legajo != estudiante->legajo))
    {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL)
    {
        if (list->head)
        {
            printf("Lista vacia \n");
        }
        else
        {
            printf("No se encontro el elemento en la lista \n");
        }
    }
    else
    {
        if (list->head == actual)
        {
            list->head = actual->next;
        }
        else
        {
            anterior->next = actual->next;
        }

        free(actual);
    }
    list->size--;
}
void eliminarListaDeEstudiantes(ListaDeEstudiantes *lista)
{
    NodoEstudiante *actual = lista->head;
    NodoEstudiante *siguiente;

    while (actual != NULL)
    {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

// Sin Usar
/// @param list
/// @param edad
/// @return Devuelve el primer estudiante que se encuentra en la lista a partir de una edad
Estudiante *getEstudiantePorLegajo(ListaDeEstudiantes *list, int legajo)
{
    if (list != NULL)
    {
        NodoEstudiante *cursor = list->head;
        while (cursor != NULL)
        {
            if (getLegajo(GetEstudiante(cursor)) == legajo)
            {
                return GetEstudiante(cursor);
            }
            cursor = cursor->next;
        }
    }
    return NULL;
}

void modificarNombreDeEstudiante(Estudiante *estud, char *nom, char *ape)
{
    // Estudiante *aux = getEstudiantePorLegajo(list, legajo);
    free(estud->nombre);
    free(estud->apellido);
    estud->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    estud->apellido = (char *)malloc((strlen(ape) + 1) * sizeof(char));
    strcpy(estud->nombre, nom);
    strcpy(estud->apellido, ape);
}
/// @brief Imprime todos los estudiantes que tengan la edad ingresada
/// @param list
/// @param edad
void imprimirEstudiantesPorRangoDeEdad(ListaDeEstudiantes *list, int edadMin, int edadMax)
{
    NodoEstudiante *cursor = list->head;
    if (cursor == NULL)
    {
        printf("El sistema no tiene estudiantes.\n");
    }
    while (cursor != NULL)
    {
        if (edadMin <= getEdad(GetEstudiante(cursor)) && getEdad(GetEstudiante(cursor)) <= edadMax)
        {
            imprimirEstudiante(GetEstudiante(cursor));
        }
        cursor = cursor->next;
    }
}

void imprimirListaDeEstudiantes(ListaDeEstudiantes *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("No se encontraron estudiantes.\n");
    }
    else
    {
        NodoEstudiante *cursor = list->head;
        while (cursor != NULL)
        {
            Estudiante *estudiante = GetEstudiante(cursor);
            imprimirEstudiante(estudiante);
            cursor = cursor->next;
        }
    }
    printf("\n");
}
// --------------------------------------------------- Lista Materias --------------------------------------------------- //

typedef struct structListaDeMaterias
{
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaDeMaterias;

ListaDeMaterias *NewListaDeMaterias()
{
    ListaDeMaterias *list = (ListaDeMaterias *)malloc(sizeof(ListaDeMaterias));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int SizeOfMat(ListaDeMaterias *list)
{
    return list->size;
}

void addMateria(ListaDeMaterias *list, Materia *materia)
{
    NodoMateria *node = NewNodoMateria(materia);
    if (node == NULL)
    {
        return;
    }
    if (SizeOfMat(list) == 0)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}
void eliminarMateria(ListaDeMaterias *list, Materia *matteria)
{

    NodoMateria *actual = list->head;
    NodoMateria *anterior = NULL;

    while (actual != NULL && (actual->datos == NULL || actual->datos->nombre != matteria->nombre))
    {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL)
    {
        if (list->head)
        {
            printf("Lista vacia \n");
        }
        else
        {
            printf("No se encontro el elemento en la lista \n");
        }
    }
    else
    {
        if (list->head == actual)
        {
            list->head = actual->next;
        }
        else
        {
            anterior->next = actual->next;
        }

        free(actual);
    }
    list->size--;
}
void eliminarListaDeMaterias(ListaDeMaterias *lista)
{
    NodoMateria *actual = lista->head;
    NodoMateria *siguiente;

    while (actual != NULL)
    {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
Materia *getMateriaPorNombre(ListaDeMaterias *list, char *nombre)
{
    NodoMateria *materia = list->head;
    while (materia != NULL)
    {
        if (strcmp(materia->datos->nombre, nombre) == 0)
        {
            return GetMateria(materia);
        }
        materia = materia->next;
    }
    return NULL;
}
void modificarNombreMateria(Materia *materia, char *nom)
{
    free(materia->nombre);
    materia->nombre = (char *)malloc((strlen(nom) + 1) * sizeof(char));
    strcpy(materia->nombre, nom);
}

void enlistarAlumnoEnMateria(Materia *materia, Estudiante *estudiante)
{
    if (materia->alumnos == NULL)
    {
        materia->alumnos = NewListaDeEstudiante();
    }

    // materia->alumnos = list_mat;
    inserFinal(materia->alumnos, estudiante);
    materia->catn_alumnos++;
}

void eliminarAlumoDeMateria(Materia *mat, Estudiante *estudiante)
{
    ListaDeEstudiantes *list_mat = NewListaDeEstudiante();
    list_mat = mat->alumnos;
    eliminarEstudiante(list_mat, estudiante);
    mat->catn_alumnos--;
}
void rendirMateria(Materia *mat, Estudiante *alumno, float promedio)
{
    if (promedio >= 4)
    {
        if (mat->alumnos_aprobados == NULL)
        {
            mat->alumnos_aprobados = NewListaDeEstudiante();
        }
        insertarOrdenadamente(mat->alumnos_aprobados, alumno);
        mat->catn_alumnos_aprobados++;
        printf("Alumno aprobo con un promedio de: %f \n", promedio);
    }
    else
    {
        if (mat->alumnos_desaprobados == NULL)
        {
            mat->alumnos_desaprobados = NewListaDeEstudiante();
        }
        insertarOrdenadamente(mat->alumnos_desaprobados, alumno);
        mat->catn_alumnos_desaprobados++;
        printf("Alumno desaprobo con un promedio de: %f \n", promedio);
    }
}

// void imprimirAlumnosDeLaMateria(Materia *mat)
// {
//     printf("Materia: %s\n", getNombreMateria(mat));
//     printf("-----Alumnos de la Materia:\n");
//     imprimirListaDeEstudiantes(mat->alumnos);
//     printf("-----Alumnos aprobados de la Materia:\n");
//     imprimirListaDeEstudiantes(mat->alumnos_aprobados);
//     printf("-----Alumnos desaprobados de la Materia:\n");
//     imprimirListaDeEstudiantes(mat->alumnos_desaprobados);

//     printf("Porcentaje de aprobados: %d por ciento", ((mat->catn_alumnos_aprobados * 100) / mat->catn_alumnos));
// }
