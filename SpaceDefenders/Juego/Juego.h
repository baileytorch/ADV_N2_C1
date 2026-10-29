#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>

#include <vector>

#include "../Entidades/NaveEnemigo.h"
#include "../Entidades/NaveJugador.h"

class Juego
{
private:
    NaveJugador jugador;

    vector<NaveEnemigo> enemigos;

public:
    Juego(/* args */);
    ~Juego();

    void iniciar();
};

#endif