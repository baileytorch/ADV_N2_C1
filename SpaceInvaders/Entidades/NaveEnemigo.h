#ifndef NAVEENEMIGO_H
#define NAVEENEMIGO_H

#include "Nave.h"
#include <string>

class NaveEnemigo: public Nave
{
public:
    NaveEnemigo(
        string nombre,
        int vida,
        int ataque
    );
    
    void disparar(
        Nave* objetivo
    ) override;
};

#endif