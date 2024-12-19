class tableroHanoi
{
public:
    tableroHanoi();                       // constructor
    void pintaTablero();                  // esta funcion pinta el tablero
    void mueveFichas(int, int, int, int); // funcion recursiva para mover las fichas entre palos
    void setNumeroFichas();               // establece el numero total de pisos de la torre
    void setMostrarMovimientos(bool);     // modifica el valor de mostarMovimientos
    int getNumeroFichas();                // devuelve el numero de pisos
    void fin();                           // funcion para ejecutar al finalizar

private:
    void pintaMovimiento(int, int); // esta funcion pinta los movimientos si el atributo mostrarMovimientos es true
    int palo[3][11];                // 3 palos y hasta 9 pisos (el [x][0] almacena el numero de fichas apiladas en cada palo
                                    // el [x][10] solo se usa para mostrar los movimientos en el caso de
                                    // elegir 9 pisos
    int numeroMovimientos;          // lleva un registro de numero de movimientos realizados
    int numeroFichas;               // numero de fichas de la trae
    bool mostrarMovimientos;        // permite seleccionar dos metodos distintos de visualizacion
};
