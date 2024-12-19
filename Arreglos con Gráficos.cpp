//programa interactivo que permite al usuario visualizar tres tipos de arreglos (unidimensional, bidimensional y tridimensional) 
//tanto en la consola como en una representación gráfica simple 
#include<stdio.h>
#include<stdlib.h>
#include<winbgim.h>
#include<graphics.h>

int opcionarreglo, opcionprograma;
char filaitoa[10],columnaitoa[10],anchoitoa[10],altoitoa[10],largoitoa[10];
void arreglobidimensional();
void entorno();
void arreglounidimensional();
void arreglomultidimensional();

int main(){
		
	do{
		system("cls");
		closegraph();
		printf("seleccione la opcion de arreglo que desea ver: \n");
		printf("1 Arreglo Unidimensional\n2 Arreglo bidimensional\n3 Arreglo Multidimensional\n");
		scanf("%d",&opcionarreglo);
		if(opcionarreglo==1){
			//entorno();
			arreglounidimensional();
			
		}
		if(opcionarreglo==2){
			arreglobidimensional();
		}
		if(opcionarreglo==3){
			arreglomultidimensional();
		}
		printf("\n1 Seguir con el programa\n2 Salir del programa\n");
		scanf("%d",&opcionprograma);
	}
	while(opcionprograma==1);
	printf("Gracias por usar este programa\n");
	//closegraph();;
	return 0;
}

void arreglounidimensional(){
	int fila;
	int matriz[2];
	for(fila=0; fila<2; fila++){
		matriz[fila]=fila+1;
		printf("Fila: %d\t", matriz[fila]);
	}
	initwindow(300,300);
	moveto(0,0);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(10,20,"Los valores son:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(10,60,"Fila:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	rectangle(25,70,65,115);
	itoa(fila,filaitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(35,80,filaitoa);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(35,190,"Representacion");
	rectangle(30,220,60,240);
	rectangle(60,220,90,240);
}
void arreglobidimensional(){
	int fila, columna;
	int matriz[2][2];
	for(fila=0; fila<2; fila++) {
		for(columna=0;columna<2;columna++){
			matriz[fila][columna] = columna+1;
			printf("Columna: %d\t", matriz[fila][columna]);
		}
		printf("\n");
	}
	initwindow(300,300);
	moveto(0,0);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(10,20,"Los valores son:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(10,60,"Fila:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(100,60,"Columna:");
	rectangle(25,70,65,115);
	itoa(fila,filaitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(35,80,filaitoa);
	rectangle(110,70,150,115);
	itoa(columna,columnaitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(120,80,columnaitoa);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(35,190,"Representacion");
	rectangle(30,220,60,240);
	rectangle(30,240,60,260);
	rectangle(60,220,90,240);
	rectangle(90,240,90,260);
}
void arreglomultidimensional(){
	int ancho,largo,alto;
	int matriz[2][2][2];
	printf("Esto es un array que representa un cubo\n");
	printf("Es complejo de graficar en consola\n");
	for(ancho=0; ancho<2; ancho++){
		for(largo=0; largo<2;largo++){
			for(alto=0; alto<2;alto++){
				matriz[ancho][largo][alto]=alto+1;
				printf("Unidad: %d\t",matriz[ancho][largo][alto]);
			}
			printf("\n\t");
		}
		printf("\n\t");
		
	}
	initwindow(300,300);
	moveto(0,0);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(10,20,"Los valores son:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(10,60,"Largo:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(100,60,"Alto:");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	outtextxy(180,60,"Ancho:");
	rectangle(25,70,65,115);
	itoa(largo,largoitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(35,80,largoitoa);
	rectangle(110,70,150,115);
	itoa(alto,altoitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(120,80,altoitoa);
	rectangle(190,70,230,115);
	itoa(ancho,anchoitoa,10);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(200,80,anchoitoa);
	rectangle(30,220,60,240);
	rectangle(40,230,70,250);
}

