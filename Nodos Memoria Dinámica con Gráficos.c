// Programa maneja una lista enlazada, permitiendo insertar nodos al inicio, medio o final, mostrar los datos almacenados y liberar
// la memoria al eliminar los nodos, hasta que el usuario elija salir.
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct NODO
{
    int valor;
    struct NODO *siguiente;
} NODO;

NODO *evaluador(const int *, const int *, NODO *, NODO *, NODO *, int *);

void main()
{
    NODO *last_ptr_stc, *first_ptr_stc, *aux_ptr_stc;
    int flag = 0, count = 0;
    unsigned int value;
    while (flag != -1)
    {
        printf("\t ********NODOS*********** \n");
        printf("\n SELECCIONE UNA OPCION PARA EL DATO \n");
        printf("1.-\t PRINCIPIO \n");
        printf("2.-\t EN MEDIO\n");
        printf("3.-\t FINAL \n");
        printf("4.-\t VER DATOS\n");
        printf("5.-\t BORRAR DATOS\n");
        scanf("%d", &flag);
        if ((count == 0))
        {
            first_ptr_stc = evaluador(&flag, &value, last_ptr_stc, first_ptr_stc, aux_ptr_stc, &count);
            last_ptr_stc = (*first_ptr_stc).siguiente;
        }
        else
        {
            first_ptr_stc = evaluador(&flag, &value, last_ptr_stc, first_ptr_stc, aux_ptr_stc, &count);
            if ((*last_ptr_stc).siguiente != NULL)
            {
                last_ptr_stc = (*last_ptr_stc).siguiente;
            }
        }
    }
}

NODO *evaluador(const int *opc, const int *value, NODO *last_ptr_stc, NODO *first_ptr_stc, NODO *aux_ptr_stc, int *count)
{
    int i;
    switch (*opc)
    {
    // Insertar al inicio
    case 1:
        printf("INTRODUCIR DATO: \n");
        scanf("%d", value);
        if ((*count) == 0)
        {
            first_ptr_stc = (NODO *)malloc(sizeof(NODO));
            (*first_ptr_stc).valor = (*value);
            printf("%d\n", (*first_ptr_stc).valor);
            (*first_ptr_stc).siguiente = (NODO *)malloc(sizeof(NODO));
            ++(*count);
        }
        else
        {
            aux_ptr_stc = first_ptr_stc;
            first_ptr_stc = (NODO *)malloc(sizeof(NODO));
            (*first_ptr_stc).valor = (*value);
            (*first_ptr_stc).siguiente = aux_ptr_stc;
            ++(*count);
        }
        break;
        // Insertar en medio
    case 2:
        printf("INTRODUCIR DATO: \n");
        scanf("%d", value);

        aux_ptr_stc = first_ptr_stc;
        for (i = 0; i < floor((*count) / 2); ++i)
        {
            aux_ptr_stc = (*aux_ptr_stc).siguiente;
        }
        last_ptr_stc = (*aux_ptr_stc).siguiente;
        (*aux_ptr_stc).siguiente = (NODO *)malloc(sizeof(NODO));
        aux_ptr_stc = (*aux_ptr_stc).siguiente;
        (*aux_ptr_stc).valor = (*value);
        (*aux_ptr_stc).siguiente = last_ptr_stc;
        aux_ptr_stc = (*aux_ptr_stc).siguiente;
        ++(*count);
        break;
        // Insertar al final
    case 3:
        printf("INTRODUCIR DATO: \n");
        scanf("%d", value);
        if ((*count) == 0)
        {
            first_ptr_stc = (NODO *)malloc(sizeof(NODO));
            (*first_ptr_stc).valor = (*value);
            printf("%d\n", (*first_ptr_stc).valor);
            (*first_ptr_stc).siguiente = (NODO *)malloc(sizeof(NODO));
            ++(*count);
        }
        else
        {
            (*last_ptr_stc).valor = *value;
            (*last_ptr_stc).siguiente = (NODO *)malloc(sizeof(NODO));
            last_ptr_stc = (*last_ptr_stc).siguiente;
            ++(*count);
        }
        break;
        // Imprimir datos
    case 4:
        if ((*count) != 0)
        {
            printf("\n|%d|\t - VALOR: %d\t ", 1, (*first_ptr_stc).valor);
            aux_ptr_stc = (*first_ptr_stc).siguiente;
            for (i = 0; i < (*count) - 1; ++i)
            {
                if ((*aux_ptr_stc).siguiente != 0)
                {
                    printf("|%d|\t - VALOR: %d\t\n", (*aux_ptr_stc).valor);
                    aux_ptr_stc = (*aux_ptr_stc).siguiente;
                }
            }
            printf("\n");
        }
        else
        {
            printf("NO HAY DATOS QUE MOSTRAR\n\n");
        }
        break;
        // Liberar memoria
    case 5:
        if ((*count) != 0)
        {
            last_ptr_stc = (*first_ptr_stc).siguiente;
            printf("DIRECCION: %d\n", first_ptr_stc);
            free(first_ptr_stc);
            printf("DIRECCION: %d\n", last_ptr_stc);
            aux_ptr_stc = (*last_ptr_stc).siguiente;
            free(last_ptr_stc);
            for (i = 0; i < (*count); ++i)
            {
                if (last_ptr_stc != 0 && aux_ptr_stc != 0)
                {
                    last_ptr_stc = aux_ptr_stc;
                    printf("DIRECCION: %d\n", last_ptr_stc);
                    aux_ptr_stc = (*last_ptr_stc).siguiente;
                    free(last_ptr_stc);
                }
            }
            (*count) = 0;
        }
        break;
    case -1:
        break;
    default:
        printf("VERIFICAR OPCION SELECCIONADA\n\n");
        break;
    }
    return first_ptr_stc;
}
