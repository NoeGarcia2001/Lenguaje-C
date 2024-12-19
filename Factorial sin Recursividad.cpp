// Programa para realizar el factorial sin utilizar recursividad.
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int numero, i, res = 1;
    printf("Ingresa un numero");
    scanf("%d", &numero);
    for (i = 1; i <= numero; i++)
    {
        printf(" %d \n", res = res * i);
    }

    system("pause");
}
