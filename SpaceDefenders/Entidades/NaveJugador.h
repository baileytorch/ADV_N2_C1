#ifndef NAVEJUGADOR_H
#define NAVEJUGADOR_H

#include "Nave.h"
#include <string>

class NaveJugador: public Nave
{
private:
    int escudo;
public:
    NaveJugador(
        string nombre
    );
    
    void disparar(
        Nave* objetivo
    ) override;

    void reparar();
};

#endif