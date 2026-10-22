#ifndef NAVEJUGADOR_H
#define NAVEJUGADOR_H

#include "Nave.h"
#include <string>

class NaveEnemigo: public Nave
{
private:
    int escudo;
public:
    NaveEnemigo(
        string nombre
    );
    
    void disparar(
        Nave* objetivo
    ) override;

    void reparar();
};

#endif