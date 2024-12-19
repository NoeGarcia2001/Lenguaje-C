// Programa del producto cartesiano de 3 conjuntos.
#include <stdio.h>

void producto(int A[], int B[], int tamA, int tamB, int C[], int tamC);

main()
{
    int A[] = {1, 2, 3, 9, 10};
    int B[] = {2, 3, 4, 5};
    int C[] = {1, 2, 3};
    int tamA = sizeof(A) / sizeof(int);
    int tamB = sizeof(B) / sizeof(int);
    int tamC = sizeof(C) / sizeof(int);

    producto(A, B, tamA, tamB, C, tamC);
}

void producto(int A[], int B[], int tamA, int tamB, int C[], int tamC)
{
    int i = 0, j = 0, t = 0;
    for (i = 0; i < tamA; i++)
    {
        for (j = 0; j < tamB; j++)
        {
            for (t = 0; t < tamC; t++)
            {
                printf("{x: %d ; y: %d ; z: %d}\n", A[i], B[j], C[t]);
            }
        }
    }
}
