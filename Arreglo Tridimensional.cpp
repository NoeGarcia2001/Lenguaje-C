//Programa que imprime los elementos de una matriz de 3×4 en formato tabular con un espaciado uniforme entre columnas.
#include<iostream>
#include<windows.h>
#include<iomanip>
#define fila 3
#define col 4

using namespace std;
int main(){
	int A[fila][col]={{0,1,9,3},{1,2,8,0},{-1,6,4,15}};
	for(int i=0; i<fila; i++){
		cout<<"\n";
		for(int j=0; j<col; j++)
		cout<<setw(2)<<A[i][j]<<"\t";
	}
	system("pause>null");
}