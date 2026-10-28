#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>

#include "../Entidades/NaveEnemigo.h"
#include "../Entidades/NaveJugador.h"

class Juego
{
private:
    NaveJugador jugador;

public:
    Juego(/* args */);
    ~Juego();
};

#endif