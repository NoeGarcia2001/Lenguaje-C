// Progrma que implementa una calculadora básica en consola que realiza las operaciones de suma, resta, multiplicación y división
// según la selección del usuario, permitiendo repetir el proceso hasta que el usuario decida salir.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

main()
{
	char resp;
	do
	{
		system("cls");
		int val1, val2, opc, suma, resta, mult, div;

		printf("************************CALCULADORA SIN GRAFICOS**************************\n\n");
		printf("1.- SUMA \n");
		printf("2.- RESTA \n");
		printf("3.- MULTIPLICACION \n");
		printf("4.- DIVISION \n");
		printf("5.- SALIR \n\n");
		printf("SELECCIONA UNA OPCION:  ");
		scanf("%d", &opc);
		while (opc < 1 || opc > 5)
		{
			printf("ERROR");
			scanf("%d", &opc);
		}

		switch (opc)
		{
		case 1:
			printf("\n\nCOLOCA EL PRIMER VALOR: ");
			scanf("%d", &val1);
			printf("\nCOLOCA EL SEGUNDO VALOR: ");
			scanf("%d", &val2);
			suma = val1 + val2;
			printf("\nEl resultado de la suma es %d \n", suma);
			break;
		case 2:
			printf("\nCOLOCA EL PRIMER VALOR: ");
			scanf("%d", &val1);
			printf("\nCOLOCA EL SEGUNDO VALOR: ");
			scanf("%d", &val2);
			resta = val1 - val2;
			printf("\nEl resultado de la resta es %d \n", resta);
			break;
		case 3:
			printf("\nCOLOCA EL PRIMER VALOR: ");
			scanf("%d", &val1);
			printf("\nCOLOCA EL SEGUNDO VALOR: ");
			scanf("%d", &val2);
			mult = val1 * val2;
			printf("\nEl resultado de la multiplicacion es %d \n", mult);
			break;
		case 4:
			printf("\nCOLOCA EL PRIMER VALOR: ");
			scanf("%d", &val1);
			printf("\nCOLOCA EL SEGUNDO VALOR: ");
			scanf("%d", &val2);
			div = val1 / val2;
			printf("\nEl resultado de la division es %d \n", div);
			break;
		case 5:
			break;
		}

		do
		{
			printf("\nDESEA CONTINUAR S/N: ");
			scanf("%s", &resp);
			resp = toupper(resp);
		} while (resp != 'S' && resp != 'N');
	} while (resp == 'S');
}
