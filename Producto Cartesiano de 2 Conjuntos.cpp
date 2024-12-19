// Programa del producto cartesiano de 2 conjuntos.
#include <stdio.h>
void producto(int A[], int B[], int tamA, int tamB);

main()
{
    int A[] = {1, 5};
    int B[] = {2, 3, 4};
    int tamA = sizeof(A) / sizeof(int);
    int tamB = sizeof(B) / sizeof(int);

    producto(A, B, tamA, tamB);
}

void producto(int A[], int B[], int tamA, int tamB)
{
    int i = 0, j = 0;
    for (i = 0; i < tamA; i++)
    {
        for (j = 0; j < tamB; j++)
        {
            printf("{x: %d ; y: %d}\n", A[i], B[j]);
        }
    }
}
