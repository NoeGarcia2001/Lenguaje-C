// Programa que implementa una calculadora gráfica que utiliza la biblioteca graphics.h para representar una interfaz de botones
// para operaciones básicas (suma, resta, multiplicación y división). Los cálculos se ingresan y manejan inicialmente en consola,
// y los resultados se muestran en la ventana gráfica junto con la interfaz.
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>

int menu(int op);
int operaciones(int a, int b, int op);

int botonesCalculadora1();
int botonesCalculadora2();
int botonesCalculadora3();
int botonesCalculadora4();
int c = 0;

main()
{
    int gd = DETECT, gm, op, res, i;
    float resF;
    char arr[50];

    menu(op);
    res = c;
    sprintf(arr, "%d", res);
    resF = 385 / 4;

    initwindow(400, 495, "CALCULADORA");
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    outtextxy(10, 10, arr);
    delay(2000);
    settextstyle(6, 0, 6);
    setcolor(2);
    rectangle(5, 5, (385), 70);

    botonesCalculadora1();
    botonesCalculadora2();
    botonesCalculadora3();
    botonesCalculadora4();

    getch();
    closegraph();
}

int menu(int op)
{
    int a, b, c;
    printf("CALCULADORA");
    printf("\n\n1.-Sumar");
    printf("\n2.-Restar");
    printf("\n3.-Multiplicar");
    printf("\n4.-Dividir");
    printf("\n\nElige una operacion: ");
    scanf("%d", &op);

    printf("\n\nIngresa el primer valor: ");
    scanf("%d", &a);
    printf("\nIngresa el segundo valor: ");
    scanf("%d", &b);

    operaciones(a, b, op);
}

int operaciones(int a, int b, int op)
{
    if (op == 1)
    {
        c = a + b;
    }
    else if (op == 2)
    {
        c = a - b;
    }
    else if (op == 3)
    {
        c = a * b;
    }
    else if (op == 4)
    {
        c = a / b;
    }
}

int botonesCalculadora1()
{
    int x, i, n;
    char ar[50];
    x = 385 / 4;

    for (i = 1; i <= 4; i++)
    {
        setcolor(9);
        rectangle((5 + (x * (i - 1))), 80, (x * i), (80 + x));
    }

    for (i = 1; i <= 3; i++)
    {
        sprintf(ar, "%d", (i + 6));
        outtextxy(30 + (95 * (i - 1)), 100, ar);
    }
    outtextxy(315, 100, "+");
}

int botonesCalculadora2()
{
    int x, i, n;
    char ar[50];
    x = 385 / 4;

    for (i = 1; i <= 4; i++)
    {
        setcolor(9);
        rectangle((5 + (x * (i - 1))), 180, (x * i), (180 + x));
    }

    for (i = 1; i <= 3; i++)
    {
        sprintf(ar, "%d", (i + 3));
        outtextxy(30 + (95 * (i - 1)), 200, ar);
    }
    outtextxy(325, 200, "-");
}

int botonesCalculadora3()
{
    int x, i, n;
    char ar[50];
    x = 385 / 4;

    for (i = 1; i <= 4; i++)
    {
        setcolor(9);
        rectangle((5 + (x * (i - 1))), 280, (x * i), (280 + x));
    }

    for (i = 1; i <= 3; i++)
    {
        sprintf(ar, "%d", i);
        outtextxy(30 + (95 * (i - 1)), 300, ar);
    }
    outtextxy(320, 300, "x");
}

int botonesCalculadora4()
{
    int x, i, n;
    char ar[50];
    x = 385 / 4;

    for (i = 1; i <= 4; i++)
    {
        rectangle((5 + (x * (i - 1))), 380, (x * i), (380 + x));
    }

    outtextxy(20, 400, "C");
    outtextxy(125, 400, "0");
    outtextxy(220, 400, "=");
    outtextxy(330, 400, "/");
}
