// Programa para realizar el factorial utilizando recursividad.
#include <stdio.h>
#include <stdlib.h>

int Factorial(int);

int main()
{
	int num;
	printf("Ingresa un numero: ");
	scanf("%d", &num);
	printf("-------\n");
	printf("El factorial de %d es de %d\n", num, Factorial(num));
	system("pause");
}

int Factorial(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else
	{
		return (Factorial(num - 1) * num);
	}
}
