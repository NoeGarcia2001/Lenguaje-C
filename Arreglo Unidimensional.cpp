// Programa que define un vector de números y calcula la suma de sus elementos.
#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	int numeros[8] = {1, 7, 7, 8};
	int suma = 0;

	for (int i = 0; i < 8; i++)
	{
		suma += numeros[i];
	}

	cout << "La suma de los elementos del vector es: " << suma << endl;

	getch();
	return 0;
}
