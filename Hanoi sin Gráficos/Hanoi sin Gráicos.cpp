//Programa de torres de Hanoi en modo consola.
#include <cstdlib>
#include <iostream>
#include "tablero.h"

int main()
{
    tableroHanoi Tablero; // instancia de la clase tableroHanoi
    Tablero.setMostrarMovimientos(true);

    int nFichas = Tablero.getNumeroFichas(); // nfichas obtiene el valor del numero de pisos total de la torre
    Tablero.mueveFichas(nFichas, 0, 1, 2);   // pasamos todas las piezas al segundo palo, es decir, palo[1]
    Tablero.fin();                           // al final muestra el numero total de movimientos realizados

    system("PAUSE");
    return 0;
}
