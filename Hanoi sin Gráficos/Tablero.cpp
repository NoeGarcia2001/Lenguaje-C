#include <iostream>
#include "tablero.h"

#define VACIO 1

using std::cin;
using std::cout;
using std::endl;

tableroHanoi::tableroHanoi()
{

    cout << "BIENVENIDO AL PROGRAMA TORRE DE HANOI\n"
         << endl;
    setNumeroFichas();
    setMostrarMovimientos(false);
    numeroMovimientos = 0;
    pintaTablero();
    system("pause");
}

void tableroHanoi::setNumeroFichas()
{
    int pisos;

    for (int i = 0; i <= 2; i++)
        for (int j = 1; j <= 10; j++)
            palo[i][j] = VACIO;

    palo[0][0] = palo[1][0] = palo[2][0] = 0; // lleva el numero de discos en cada palo

    cout << "Introduzca el numero de pisos de la torres (1-9)\n\n";

    do
    {
        cin >> pisos;
        if (pisos > 9 || pisos < 1)
        {
            cout << "El numero de pisos introducido es incorrecto\n";
            cout << "Introduzca el numero de pisos de la torre (1-9) \n\n";
            pisos = -1;
        }
    } while (pisos == -1);

    numeroFichas = pisos;
    palo[0][0] = pisos; // ponemos todos los discos en el primer palo

    int anchuraDisco = pisos * 2 + 1;
    for (int i = 1; i <= pisos; i++)
    {
        palo[0][i] = anchuraDisco;
        anchuraDisco -= 2;
    }
}

void tableroHanoi::setMostrarMovimientos(bool mm)
{
    mostrarMovimientos = mm;
}

int tableroHanoi::getNumeroFichas()
{
    return numeroFichas;
}

void tableroHanoi::mueveFichas(int numFichas, int origen, int destino, int auxiliar)
{

    if (numFichas == 1)
    {

        if (mostrarMovimientos)
            pintaMovimiento(origen, destino);

        // pasamos una ficha del origen al destino
        int &topDestino = palo[destino][0];
        int &topOrigen = palo[origen][0];

        palo[destino][++topDestino] = palo[origen][topOrigen];
        palo[origen][topOrigen--] = VACIO;

        ++numeroMovimientos;

        if (!mostrarMovimientos)
            pintaTablero();
        system("pause");
    }
    else
    {
        mueveFichas(numFichas - 1, origen, auxiliar, destino);
        mueveFichas(1, origen, destino, auxiliar);
        mueveFichas(numFichas - 1, auxiliar, destino, origen);
    }
}

void tableroHanoi::pintaTablero()
{

    cout << "\n\n\n";
    char cEspacio = 32, cFicha = 177, cPalo = 186, cBase = 178; // distintos caracteres usados

    for (int altura = 10; altura >= 1; altura--)
    { // pintamos los palos de arriba a abajo, claro

        for (int npalo = 0; npalo <= 2; npalo++)
        {
            int nespacios = (21 - palo[npalo][altura]) / 2; // nespacios es el numero de espacios a pintar para centrar las pilas en cada palo

            // Pintamos los espacios necesarios a la izquierda de la pila
            for (int espacios = 1; espacios <= nespacios; espacios++)
                cout << cEspacio;

            // Pinta la ficha (si es que hay en esa altura) o el palo
            if (palo[npalo][altura] == VACIO)
                cout << cPalo; // pinta el palo
            else
                for (int solido = 1; solido <= palo[npalo][altura]; solido++)
                    cout << cFicha; // pinta la ficha

            // Pintamos los espacios necesarios a la derecha de la pila
            for (int espacios = 1; espacios <= nespacios; espacios++)
                cout << cEspacio;
        }
        cout << endl;
    }

    // Por ultimo pintamos la base del tablero
    for (int i = 0; i <= 63; i++)
        cout << cBase;

    cout << "\n\n";
}

void tableroHanoi::fin()
{
    // Muestra el tablero en la posicion final si es necesario
    if (mostrarMovimientos)
        pintaTablero();

    cout << "\n\n\nFIN DEL JUEGO\nSE HAN REALIZADO " << numeroMovimientos << " MOVIMIENTOS" << endl;
}

void tableroHanoi::pintaMovimiento(int origen, int destino)
{
    cout << "\n\n\n";

    // Pintamos una flecha que indica el movimiento
    // esta flecha va desde el palo origen al palo destino del movimiento
    char cEspacio = 32, cLinea = 196, cLineaV = 197, carImpr;
    carImpr = cEspacio; // usamos carImpr para imprimir espacios o lineas horizontales

    for (int npalo = 0; npalo <= 2; npalo++)
    {                                 // cada palo
        for (int i = 1; i <= 10; i++) // espacios a la izquierda del palo
            cout << carImpr;

        // pintamos los extremos de la flecha si corresponde
        if (npalo == origen || npalo == destino)
        {
            if (destino > origen)
                cout << ">";
            else
                cout << "<";

            // cambiamos carImpr para que deje de imprimir lineas o viceversa
            carImpr = (carImpr == cEspacio) ? cLinea : cEspacio;
        }
        else
            cout << carImpr;

        for (int i = 1; i <= 10; i++) // espacios a la derecha del palo
            cout << carImpr;
    }

    // Ahora vamos a pintar el tablero, resaltando la ficha que se va a mover
    // para eso mostrarmos la pieza levantada una posicion
    int topOrigen = palo[origen][0];

    palo[origen][topOrigen + 1] = palo[origen][topOrigen];
    palo[origen][topOrigen] = VACIO;

    pintaTablero();

    // deshacemos el cambio anterior
    palo[origen][topOrigen] = palo[origen][topOrigen + 1];
    palo[origen][topOrigen + 1] = VACIO;
}
