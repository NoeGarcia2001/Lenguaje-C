//Programa de las torres de Hanoi con interfaz gráfica.
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define YSize 20

void SetMode();
void Box();
void dibujarHanoi(int);
void mover(int, int, int);
void torres(int, int, int, int);

int n, DELAY;
int IsManual = 0, flag = 1;

// Detecta donde esta el disco a mover
int DiskIsIn[9];
// Fija la posicion al apilarse
int PosInPeg[9];
int DiskCount[3];

int main()
{
	int i;
	// Lectura de Datos
	do
	{
		printf("");
		printf("\nIntroduzca el Numero de Discos De 1 a 3: ");
		scanf("%d", &n);
	} while ((n < 1) && (n > 3));

	// Tiempo de animaci�n
	DELAY = 20;

	// Inicializaci�n de ventana
	SetMode();
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	setbkcolor(BLACK);
	cleardevice();
	setcolor(WHITE);
	outtextxy(150, 10, "***TORRES DE HANOI***");
	// L�neas Horizontales
	line(40, 250, 180, 250);
	line(260, 250, 390, 250);
	line(460, 250, 600, 250);
	// Nombre de las Torres
	outtextxy(40, 300, "Torre A");
	outtextxy(270, 300, "Torre B");
	outtextxy(490, 300, "Torre C");
	// L�neas Verticales
	line(105, 100, 105, 250);
	line(325, 100, 325, 250);
	line(535, 100, 535, 250);

	DiskCount[0] = n;
	DiskCount[1] = 0;
	DiskCount[2] = 0;

	// Ordena los discos dependiendo de la entrada
	for (i = 0; i < n; i++)
	{
		PosInPeg[i] = i;
		DiskIsIn[i] = 0;
	}

	dibujarHanoi(n);
	torres(n, 0, 2, 1);
	getch();
	closegraph();
	return 0;
}

void SetMode()
{
	int gdriver = VGA, gmode = VGAMED;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
}

// Dibujado del contenedor y discos
void Box(int x1, int y1, int x2, int y2, int doit = 1)
{
	int c2 = BLACK,
		c1 = BLACK;
	if (doit)
	{
		if (flag == 0)
			flag = 1;
		else
			flag = 0;
		switch (flag)
		{
		case 0:
			c1 = BLACK;
			c2 = BLACK;
			break;
		case 1:
			c2 = BLACK;
			c1 = BLACK;
			break;
		}
	}
	bar(x1, y1, x2, y2);
	setcolor(c1);
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	setcolor(c2);
	line(x1, y2, x2, y2);
	line(x2, y1 + 1, x2, y2);
}

void dibujarHanoi(int n)
{
	int i,
		x,
		y,
		size;
	for (i = 0; i < n; i++)
	{
		x = 5 + (DiskIsIn[i] * 220) + ((4 - i) * 20);
		y = 150 + PosInPeg[i] * 30;
		size = 40 + i * 40;
		setfillstyle(SOLID_FILL, 10 + i);
		Box(x, y, x + size, y + YSize);
	}
}

void mover(int disco, int inicio, int destino)
{
	int x,
		y,
		size = disco * 40,
		tx, // Posicion del poste en X
		ty; // Posicion del poste en Y

	x = 5 + (DiskIsIn[disco - 1] * 215) + ((5 - disco) * 20);
	y = 150 + PosInPeg[disco - 1] * 30;

	do
	{
		// L�neas Verticales
		setcolor(WHITE);
		line(105, 100, 105, 250);
		line(325, 100, 325, 250);
		line(535, 100, 535, 250);
		setfillstyle(SOLID_FILL, BLACK);
		bar(x, y, x + size, y + YSize);
		y -= 30;
		setfillstyle(SOLID_FILL, 9 + disco);
		Box(x, y, x + size, y + YSize);
		// comprueba si hay introduccion de datos por teclado, sale si lo hay
		if (IsManual)
			getch();
		else
			delay(DELAY);
	} while (y > 60);

	tx = 5 + (destino * 215) + ((5 - disco) * 20);

	do
	{
		// L�neas Verticales
		setcolor(WHITE);
		line(105, 100, 105, 250);
		line(325, 100, 325, 250);
		line(535, 100, 535, 250);
		setfillstyle(SOLID_FILL, BLACK);
		bar(x, y, x + size, y + YSize);
		if (tx < x)
			x -= 43;
		else
			x += 43;

		setfillstyle(SOLID_FILL, 9 + disco);
		Box(x, y, x + size, y + YSize);

		if (IsManual)
			getch();
		else
			delay(DELAY);
	} while (x != tx);

	PosInPeg[disco - 1] = n - 1 - DiskCount[destino];
	DiskCount[destino]++;
	DiskCount[inicio]--;
	DiskIsIn[disco - 1] = destino;

	ty = 150 + PosInPeg[disco - 1] * 30;
	do
	{
		// L�neas Verticales
		setcolor(WHITE);
		line(105, 100, 105, 250);
		line(325, 100, 325, 250);
		line(535, 100, 535, 250);
		setfillstyle(SOLID_FILL, BLACK);
		bar(x, y, x + size, y + YSize);
		y += 30;
		setfillstyle(SOLID_FILL, 9 + disco);
		Box(x, y, x + size, y + YSize);

		if (IsManual)
			getch();
		else
			delay(DELAY);
	} while (y < ty);
	// L�neas Verticales
	setcolor(WHITE);
	line(105, 100, 105, 250);
	line(325, 100, 325, 250);
	line(535, 100, 535, 250);
}

void torres(int n, int inicio, int destino, int auxiliar)
{
	if (n == 1)
	{
		mover(1, inicio, destino);
		return;
	}
	// Lee la entrada del teclado, si es de cualquier tipo sale
	if (kbhit())
		return;

	torres(n - 1, inicio, auxiliar, destino);

	// Lee la entrada del teclado, si es de cualquier tipo sale
	if (kbhit())
		return;
	mover(n, inicio, destino);
	torres(n - 1, auxiliar, destino, inicio);
}
