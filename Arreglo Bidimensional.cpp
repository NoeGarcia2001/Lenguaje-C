// Programa que imprime los elementos de las dos primeras filas de una matriz y encuentra el menor valor en esas filas.
#include <iostream>
#include <cstdlib>

using namespace std;
void EM_Matriz(int x[50][50], int f, int c);

int main()
{
	int x[50][50] = {
		//  0  1  2  3  4
		{45, 21, 11, 10, 3}, // fila 0
		{62, 10, 20, 32, 9}	 // fila 1
	};

	cout << x[0][0] << endl;
	cout << x[0][1] << endl;
	cout << x[0][2] << endl;
	cout << x[0][3] << endl;
	cout << x[0][4] << endl;
	cout << x[1][0] << endl;
	cout << x[1][1] << endl;
	cout << x[1][2] << endl;
	cout << x[1][3] << endl;
	cout << x[1][4] << endl;

	EM_Matriz(x, 2, 5);

	return 0;
}

void EM_Matriz(int x[50][50], int f, int c)
{
	int menor = x[0][0];
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
		{
			if (x[i][j] < menor)
				menor = x[i][j];
		}
	cout << "Elemento menor es: " << menor << endl;
}
